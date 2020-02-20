#include "printf.h"
#include <limits.h>

size_t	ft_len_of_int(long long i)
{
	size_t	res;

	res = 1;
	if (i < 0)
	{
		i *= -1;
		res++;
	}
	while (i >= 10)
	{
		res++;
		i /=10;
	}
	return (res);
}

void	di_print_with_minus(t_printf *list, long long x)
{
	if ((list->flag == '+' || list->flag2 == '+') && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	if ((list->flag == ' ' || list->flag2 == ' ') && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= - 1;
		if (list->precision > list->len_of_x)
			list->widthofline--;
	}
	if (list->len_of_x > 0)
		list->len_of_x = ft_len_of_int(x);
	
	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	if (list->len_of_x > 0)
	{
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
		list->widthofline -= list->len_of_x;
		list->widthofcontent -= list->len_of_x;
	}
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	/*
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			if (list->flag == '+' && (int)x >= 0)
			{
					ft_putchar_cow('+', list);
					list->widthofline--;
					list->widthofcontent--;
			}
			ft_putstr_cow(ft_itoa(x), list);
			list->widthofline -= ft_len_of_int(x);
			list->widthofcontent -= ft_len_of_int(x);
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	*/
}

void	presicion_over_len(t_printf *list, long long x)
{
	if (list->width > list->precision && (int)x < 0)
		list->widthofline--;
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((list->flag == '+' || list->flag2 == '+') && x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	if (x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		list->widthofline--;
	}
	//!!! list->len_of_x ft_len_of_int(x)
	//если x < 0 перед входом в функцию, то функция принимает уже x > 0, соотвественно длина на 1 меньше(и так и должно и быть) 
	while (list->widthofcontent > ft_len_of_int(x))
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
}

void	di_print_without_minus(t_printf *list, long long x)
{
	if ((list->flag == ' ' || list->flag2 == ' ') && list->width >= list->len_of_x && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flag != '0' && list->flag2 != '0')))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}

	if ((list->flag == '+' || list->flag2 == '+') && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flag == '0' || list->flag2 == '0')
		{
			if ((int)x < 0)
			{
				ft_putchar_cow('-', list);
				x *= -1;
				list->widthofcontent--;
				list->widthofline--;
			}
			ft_putchar_cow('0', list);
		}
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
}

void	d_and_i(t_printf *list)
{
	intmax_t x;

	//printf("%s\n", list->length);
	if (ft_strcmp(list->length,"l") == 0)
		x = (long)va_arg(list->ap, long int);
	else if (ft_strcmp(list->length,"ll") == 0)
		x = (long long)va_arg(list->ap, long long int);
	else if (ft_strcmp(list->length,"hh") == 0)
		x = (signed char)va_arg(list->ap, int);
	else if (ft_strcmp(list->length,"h") == 0)
		x = (short)va_arg(list->ap, int);
	else
		x = (int)va_arg(list->ap, long int);

	x = (intmax_t)x;

	list->len_of_x = ft_len_of_int(x);

	if (list->precision == 0 && list->np == 'n')
		list->len_of_x = 0;
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision > list->len_of_x && list->precision > list->width)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}

	if (list->precision < list->len_of_x)
		list->widthofcontent = list->len_of_x;
	else
		list->widthofcontent = list->precision;
	
	if (((list->flag == '+' || list->flag2 == '+') || \
		(list->flag == ' ' && (list->len_of_x + 1 > list->width))) && x >= 0)
	{
		if (list->flag == '+' || list->flag2 == '+')
			list->widthofcontent++;
		if (list->widthofline < list->widthofcontent || list->flag == ' ')
			list->widthofline++;
	}
	if ((list->flag == '-' || list->flag2 == '-') && (list->width > list->widthofcontent))
		di_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		presicion_over_len(list, x);
	else
		di_print_without_minus(list, x);
}
