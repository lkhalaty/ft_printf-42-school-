/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:03:38 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 01:03:41 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_p(int n)
{
	if (n > 9)
		ft_putchar(n + 87);
	if (n <= 9)
		ft_putchar(n + 48);
	return (1);
}

void	ft_put_pp(long long unsigned int n)
{
	if (n >= 16)
		ft_put_pp(n / 16);
	ft_putnbr_p(n % 16);
}

int		ft_put_p(t_table t, long long unsigned int n)
{
	int len;
	int i;

	i = 0;
	len = p_len(n);
	if (!t.minus)
		i += ft_space_zero(' ', t.width - len - 2);
	i += write(1, "0x", 2);
	ft_put_pp(n);
	if (t.minus)
		i += ft_space_zero(' ', t.width - len - 2);
	return (i + len);
}

int		ft_put_percent(t_table t)
{
	if (t.minus)
		ft_space_zero('%', 1);
	if (t.zero)
		ft_space_zero('0', t.width - 1);
	if (!t.zero)
		ft_space_zero(' ', t.width - 1);
	if (!(t.minus))
		ft_space_zero('%', 1);
	return (t.width);
}
