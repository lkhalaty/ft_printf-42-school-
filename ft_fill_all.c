/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:53:13 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 11:53:15 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_count(t_table *t)
{
	t->t_i = 0;
	t->t_bytes = 0;
}

void		ft_fill_blank(t_table *t)
{
	t->zero = 0;
	t->minus = 0;
	t->width = 0;
	t->dot = 0;
	t->presicion = 0;
	t->type = '0';
}

int			ft_fill_number(t_table *t, char *format, va_list args)
{
	int number;

	number = 0;
	if (format[t->t_i] != '*')
	{
		while (format[t->t_i] >= '0' && format[t->t_i] <= '9')
		{
			number = number * 10 + (format[t->t_i] - '0');
			t->t_i++;
		}
	}
	if (format[t->t_i] == '*')
	{
		number = (va_arg(args, int));
		t->t_i++;
	}
	return (number);
}

void		ft_correct_flags(t_table *t)
{
	if (t->width < 0)
	{
		t->width = (t->width) * (-1);
		t->minus = 1;
	}
	if (t->zero == 1 && t->minus == 1)
		t->zero = 0;
}

void		ft_fill_flags(t_table *t, char *format, va_list args)
{
	if (format[t->t_i] == '-')
	{
		t->minus = 1;
		t->t_i++;
	}
	else if (format[t->t_i] == '0')
	{
		t->zero = 1;
		t->t_i++;
	}
	if (format[t->t_i] == '-')
	{
		t->minus = 1;
		t->t_i++;
	}
	t->width = ft_fill_number(t, format, args);
	if (format[t->t_i] == '.')
	{
		t->dot = 1;
		t->t_i++;
		t->presicion = ft_fill_number(t, format, args);
	}
	t->type = format[t->t_i];
	ft_correct_flags(t);
}
