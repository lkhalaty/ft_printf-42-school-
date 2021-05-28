/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:31:38 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 01:31:40 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_space_zero(char c, int n)
{
	int i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (i - 1);
}

void	ft_put_module(int n, char *s)
{
	ft_putchar(s[n]);
}

int		ft_put_division(unsigned int n, unsigned int ndiv, char *s)
{
	int i;

	i = 0;
	if (n >= ndiv)
		i += ft_put_division(n / ndiv, ndiv, s);
	ft_put_module(n % ndiv, s);
	i++;
	return (i);
}
