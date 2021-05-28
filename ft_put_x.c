/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:56:15 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 00:56:17 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_x(t_table t, unsigned int n)
{
	int len;
	int zero_size;
	int space_size;
	int i;

	i = 0;
	len = x_len(n, 16);
	len = ((n == 0 && t.dot && t.presicion >= 0) ? 0 : len);
	zero_size = ((t.presicion >= len) ? t.presicion - len : 0);
	if (t.zero && !t.dot)
		zero_size = t.width - len;
	space_size = ((t.presicion >= len) ? t.width - t.presicion : t.width - len);
	if (t.zero && !t.dot)
		space_size = 0;
	if (!t.minus)
		i += ft_space_zero(' ', space_size);
	if (t.presicion || t.zero)
		i += ft_space_zero('0', zero_size);
	if (len)
		i += ft_put_division(n, 16, s_lc);
	if (t.minus)
		i += ft_space_zero(' ', space_size);
	return (i);
}

int		ft_put_xx(t_table t, unsigned int n)
{
	int len;
	int zero_size;
	int space_size;
	int i;

	i = 0;
	len = x_len(n, 16);
	len = ((n == 0 && t.dot && t.presicion >= 0) ? 0 : len);
	zero_size = ((t.presicion >= len) ? t.presicion - len : 0);
	if (t.zero && !t.dot)
		zero_size = t.width - len;
	space_size = ((t.presicion >= len) ? t.width - t.presicion : t.width - len);
	if (t.zero && !t.dot)
		space_size = 0;
	if (!t.minus)
		i += ft_space_zero(' ', space_size);
	if (t.presicion || t.zero)
		i += ft_space_zero('0', zero_size);
	if (len)
		i += ft_put_division(n, 16, s_uc);
	if (t.minus)
		i += ft_space_zero(' ', space_size);
	return (i);
}
