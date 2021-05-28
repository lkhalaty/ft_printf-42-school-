/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:26:55 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 01:26:59 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		x_len(unsigned int n, unsigned int ndiv)
{
	int i;

	i = 1;
	if (n == 0)
		return (1);
	while (n >= ndiv)
	{
		n = n / ndiv;
		i = i + 1;
	}
	return (i);
}

int		p_len(long long unsigned int n)
{
	int i;

	i = 1;
	if (n == 0)
		return (1);
	while (n >= 16)
	{
		n = n / 16;
		i = i + 1;
	}
	return (i);
}
