/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:52 by hlikely           #+#    #+#             */
/*   Updated: 2020/02/24 16:57:35 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <ctype.h>

# include <stdio.h>

typedef	struct 	s_printf
{
	const char	*format;
	char		flags[6];
	char		*f_copy;
	size_t		width;
	size_t		precision;
	char		length[3];
	char		type;
	size_t		widthofline;
	size_t		widthofcontent;
	size_t		base;
	va_list		ap;
	int			cow;
	char		np;
	char		nw;
	int			i;
	size_t		len_of_x;
	char		*types;
	char		*args;
	char		*cons;
}				t_printf;

typedef union 	s_double
{
	double d;
	struct
	{
		unsigned long long m: 52;
		unsigned long long e: 11;
		unsigned long long s: 1;
	}			part;
}				t_double;

//ft_printf
void			display(t_printf *list);
int				ft_printf(const char *format, ...);
t_printf		*newlist_with_printf();
int				init(t_printf *list);
void			reset_list(t_printf *list);

// parsing 
t_printf		*flag(t_printf *list);
t_printf		*width(t_printf *list);
t_printf		*precision(t_printf *list);
t_printf		*length(t_printf *list);
t_printf		*type(t_printf *list);

//type c
void			type_c(t_printf *list);
void			c_width(t_printf *list, unsigned int c);
void			c_width_minus(t_printf *list, unsigned int c);

//type s
void			type_s(t_printf *list);
void			str_print_with_minus(t_printf *list, char *str);
void			str_print_without_minus(t_printf *list, char *str);

//type d
void			type_di(t_printf *list);
void			di_print_without_minus(t_printf *list, long long x);
void			di_print_with_minus(t_printf *list, long long x);
void			presicion_over_len(t_printf *list, long long x);

//type p
void			type_p(t_printf *list);

//type u
void			type_u(t_printf *list);
void			u_print_without_minus(t_printf *list, long long x);
void			u_presicion_over_len(t_printf *list, long long x);
void			u_print_with_minus(t_printf *list, long long x);

//type x
void			type_x(t_printf *list);
void			x_print_without_minus(t_printf *list, long long x);
void			x_presicion_over_len(t_printf *list, long long x);
void			x_print_with_minus(t_printf *list, long long x);

//type o
void			type_o(t_printf *list);
void			o_print_with_minus(t_printf *list, long long x);
void			o_presicion_over_len(t_printf *list, long long x);
void			o_print_without_minus(t_printf *list, long long x);

//add_func
void			sharp_x(t_printf *list);
void			ft_putchar_cow(char c, t_printf *list);
void			ft_putstr_cow(char const *s, t_printf *list);
size_t			ft_len_of_int(long long i);

//type other
void   			type_other(t_printf *list);
void			display_gap(t_printf *list, char c, int len, int update_len);

void			divis(unsigned long long *arr, int i, int num);
int				lennum(long long n);
char			*adv_ft_itoa(long long n, int base, char c);
size_t			lennum_base(long long n, int base);
void			type_f_and_F(t_printf *list);
char			*handling_float(double d, int countofel, int pow, t_printf *list);
char			*nole(void);
void			addit(unsigned long long *arr, int i, unsigned long long num);
void			mult(unsigned long long *arr, int i, int num, int end);



#endif
