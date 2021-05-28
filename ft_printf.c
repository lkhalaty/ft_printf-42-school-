/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:38:17 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 12:17:50 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_print(t_table t, va_list args)
{
	int i;

	i = 0;
	if (t.type == 's')
		i = ft_put_s(t, va_arg(args, char *));
	if (t.type == 'c')
		i = ft_put_c(t, va_arg(args, int));
	if (t.type == 'u')
		i = ft_put_u(t, va_arg(args, unsigned int));
	if (t.type == 'd' || t.type == 'i')
		i = ft_put_di(t, va_arg(args, int));
	if (t.type == 'x')
		i = ft_put_x(t, va_arg(args, unsigned int));
	if (t.type == 'X')
		i = ft_put_xx(t, va_arg(args, unsigned int));
	if (t.type == 'p')
		i = ft_put_p(t, va_arg(args, long long unsigned int));
	if (t.type == '%')
		i = ft_put_percent(t);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_table	t;

	va_start(args, format);
	ft_fill_count(&t);
	while (format[t.t_i] != '\0')
	{
		if (format[t.t_i] == '%')
		{
			t.t_i++;
			if (format[t.t_i] == '%')
				t.t_bytes += ft_putchar(format[t.t_i]);
			else
			{
				ft_fill_blank(&t);
				ft_fill_flags(&t, (char *)format, args);
				t.t_bytes += ft_check_print(t, args);
			}
			t.t_i++;
		}
		else
			t.t_bytes += ft_putchar(format[t.t_i++]);
	}
	va_end(args);
	return (t.t_bytes);
}
