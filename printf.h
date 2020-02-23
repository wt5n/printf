#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <ctype.h>

# include <stdio.h>
# define SPECS "cspdiuoxX%"
# define ARGS "lhjz"
# define CONS "-+ 0#"

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

int				ft_printf(const char *format, ...);
t_printf		*newlist_with_printf();
t_printf		*flag(t_printf *list);
t_printf		*width(t_printf *list);
t_printf		*precision(t_printf *list);
t_printf		*length(t_printf *list);
t_printf		*type(t_printf *list);
void			display(t_printf *list);
void			type_c(t_printf *list);
void			c_width(t_printf *list, unsigned int c);
void			c_width_minus(t_printf *list, unsigned int c);
void			type_s(t_printf *list);
void			str_print_with_minus(t_printf *list, char *str);
void			str_print_without_minus(t_printf *list, char *str);
void			d_and_i(t_printf *list);
size_t			ft_len_of_int(long long i);
void			di_print_without_minus(t_printf *list, long long x);
void			di_print_with_minus(t_printf *list, long long x);
void			presicion_over_len(t_printf *list, long long x);
void			type_p(t_printf *list);
void			type_u(t_printf *list);
void			u_print_without_minus(t_printf *list, long long x);
void			u_presicion_over_len(t_printf *list, long long x);
void			u_print_with_minus(t_printf *list, long long x);
void			type_x_and_X(t_printf *list);
void			x_print_without_minus(t_printf *list, long long x);
void			x_presicion_over_len(t_printf *list, long long x);
void			x_print_with_minus(t_printf *list, long long x);

char			*adv_ft_itoa(long long n, int base, char c);
size_t			lennum_base(long long n, int base);
void			type_f_and_F(t_printf *list);
char			*handling_float(double d, int countofel, int pow, t_printf *list);
char			*nole(void);
void			ft_putchar_cow(char c, t_printf *list);
void			ft_putstr_cow(char const *s, t_printf *list);
void			addit(unsigned long long *arr, int i, unsigned long long num);
void			mult(unsigned long long *arr, int i, int num, int end);
long 			change_length_di(t_printf *list, long long x);
void 			change_length_u_x(t_printf *list, long long x);
void 			change_length_f_e_a_g(t_printf *list, double x);

void			type_o(t_printf *list);
void			sharp_x(t_printf *list);
void	divis(unsigned long long *arr, int i, int num);
int		lennum(long long n);

#endif
