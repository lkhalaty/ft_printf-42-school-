/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:53:36 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 00:53:38 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_c(t_table t, char c)
{
	int i;

	i = 0;
	if (t.minus)
		i += ft_putchar(c);
	if (t.width >= 2)
		i += ft_space_zero(' ', t.width - 1);
	if (!(t.minus))
		i += ft_putchar(c);
	return (i);
}

int		ft_put_s(t_table t, char *s)
{
	int i;
	int slice_size;
	int space_size;

	if (!s)
		s = "(null)";
	slice_size = ft_strlen(s);
	if (t.dot && t.presicion >= 0)
		slice_size = ((t.presicion >= ft_strlen(s)) ?
		ft_strlen(s) : t.presicion);
	if (t.dot && t.presicion < 0)
		slice_size = ft_strlen(s);
	space_size = (t.width - slice_size) > 0 ? t.width - slice_size : 0;
	i = 0;
	if (t.minus)
		while (i < slice_size)
			ft_putchar(s[i++]);
	ft_space_zero(' ', space_size);
	i = 0;
	if (!(t.minus))
		while (i < slice_size)
			ft_putchar(s[i++]);
	return (slice_size + space_size);
}
