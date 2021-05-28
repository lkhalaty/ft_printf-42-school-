/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:20:31 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 01:20:33 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_di_neg(t_table t, int n)
{
	int len;
	int zero_size;
	int space_size;

	len = 0;
	zero_size = 0;
	space_size = 0;
	n = n * (-1);
	len = (t.dot && t.presicion == 0 && n == 0) ? 0 : x_len(n, 10);
	zero_size = ((t.presicion > len) ? t.presicion - len : 0);
	if (t.zero && !t.presicion)
		zero_size = t.dot ? 0 : t.width - len - 1;
	space_size = t.presicion >= len ? t.width - t.presicion : t.width - len;
	if (t.zero && !t.presicion)
		space_size = t.dot ? t.width - len : 0;
	if (!t.minus)
		len += ft_space_zero(' ', space_size - 1);
	len += ft_space_zero('-', 1);
	if (t.presicion || t.zero)
		len += ft_space_zero('0', zero_size);
	if (len)
		ft_put_division(n, 10, s_c);
	if (t.minus)
		len += ft_space_zero(' ', space_size - 1);
	return (len);
}

int		ft_put_di(t_table t, int n)
{
	int len;
	int zero_size;
	int space_size;
	int sign;

	len = 0;
	sign = (n >= 0 ? 1 : -1);
	zero_size = 0;
	space_size = 0;
	if (sign == 1)
		len = ft_put_u(t, n);
	if (sign == -1)
		len = ft_put_di_neg(t, n);
	return (len);
}
