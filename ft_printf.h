/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:09:04 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/05/26 12:10:25 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_table
{
	int			t_i;
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			presicion;
	char		type;
	int			t_bytes;
}				t_table;

# define s_lc	"0123456789abcdef"
# define s_uc	"0123456789ABCDEF"
# define s_c		"0123456789"

void			ft_fill_blank(t_table *t);
void			ft_fill_count(t_table *t);
void			ft_fill_flags(t_table *t, char *format, va_list args);
int				ft_fill_number(t_table *t, char *format, va_list args);
void			ft_correct_flags(t_table *t);
int				n_positive_len(unsigned int n);
int				x_len(unsigned int n, unsigned int ndiv);
int				p_len(long long unsigned int n);
int				ft_printf(const char *str, ...);
int				ft_space_zero(char c, int n);
int				ft_put_c(t_table t, char c);
int				ft_put_s(t_table t, char *s);
int				ft_put_u(t_table t, unsigned int n);
int				ft_put_di(t_table t, int n);
int				ft_put_di_neg(t_table t, int n);
int				ft_put_x(t_table t, unsigned int n);
int				ft_put_xx(t_table t, unsigned int n);
int				ft_put_p(t_table t, long long unsigned int n);
int				ft_put_percent(t_table t);
int				ft_check_print(t_table t, va_list args);
int				ft_strlen(char *s);
int				ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_put_module(int n, char *s);
int				ft_put_division(unsigned int n, unsigned int ndiv, char *s);

#endif
