#include "printf.h"

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
	if (list->flag == '+' && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= - 1;
		if (list->precision > list->len_of_x)
			list->widthofline--;
	}
	list->len_of_x = ft_len_of_int(x);
	
	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	ft_putstr_cow(ft_itoa(x), list);
	list->widthofline -= list->len_of_x;
	list->widthofcontent -= list->len_of_x;
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
	
	ft_putstr_cow(ft_itoa(x), list);
}

void	di_print_without_minus(t_printf *list, long long x)
{
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
	
	ft_putstr_cow(ft_itoa(x), list);
}

void	d_and_i(t_printf *list)
{
	long long x;

	//было (list->ap, long long), что не работает при минусовых числах
	x = va_arg(list->ap, int);
	list->len_of_x = ft_len_of_int(x);
	if (ft_strcmp(list->length, "Q"))
	{
		x = change_length_di(list, x);
		//printf("after:%ld\n", x);
	}
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision < list->len_of_x && list->precision > 0)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}

	if (list->precision < list->len_of_x)
		list->widthofcontent = list->len_of_x;
	else
		list->widthofcontent = list->precision;
	
	if (((list->flag == '+' || list->flag2 == '+') || list->flag == ' ') && x >= 0)
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
