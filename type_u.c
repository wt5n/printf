#include "printf.h"

void	u_print_with_minus(t_printf *list, long long x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putstr_cow(ft_itoa(x), list);
			list->widthofline -= ft_len_of_int(x);
			list->widthofcontent -= ft_len_of_int(x);
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	u_presicion_over_len(t_printf *list, long long x)
{
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		list->widthofline--;
	}
	while (list->widthofcontent > list->widthofline)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	ft_putstr_cow(ft_itoa(x), list);
}

void	u_print_without_minus(t_printf *list, long long x)
{
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flag == '0')
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

void	type_u(t_printf *list)
{
	long long x;

	x = va_arg(list->ap, long long);
	if (x < 0)
		ft_putstr_cow("4294967269", list);
	else
	{
		if (list->width > ft_len_of_int(x))
			list->widthofline = list->width;
		else
		{
			if (list->precision < ft_len_of_int(x) && list->precision > 0)
				list->widthofline = list->precision;
			else
				list->widthofline = ft_len_of_int(x);
		}
		if (list->precision < ft_len_of_int(x))
			list->widthofcontent = ft_len_of_int(x);
		else
			list->widthofcontent = list->precision;
		if (list->precision > ft_len_of_int(x) - 1)
			u_presicion_over_len(list, x);
		else if ((list->flag == '-') && (list->width > list->widthofcontent))
			u_print_with_minus(list, x);
		else
			u_print_without_minus(list, x);
	}
}
