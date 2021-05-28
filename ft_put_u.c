/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:04:50 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 01:04:54 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_u(t_table t, unsigned int n)
{
	int len;
	int zero_size;
	int space_size;

	len = (t.dot && t.presicion == 0 && n == 0) ? 0 : x_len(n, 10);
	zero_size = ((t.presicion >= len) ? t.presicion - len : 0);
	if (t.zero && !t.presicion)
		zero_size = ((!t.dot) ? t.width - len : 0);
	space_size = ((t.presicion >= len) ? t.width - t.presicion : t.width - len);
	if (t.zero && !t.presicion)
		space_size = ((!t.dot) ? 0 : t.width - len);
	if (!t.minus)
		ft_space_zero(' ', space_size);
	if (t.presicion || t.zero)
		ft_space_zero('0', zero_size);
	if (len)
		ft_put_division(n, 10, s_c);
	if (t.minus)
		ft_space_zero(' ', space_size);
	if (space_size >= 0)
		len += space_size;
	if (zero_size >= 0)
		len += zero_size;
	return (len);
}
