#include "printf.h"

void	fF_print_with_minus(t_printf *list, double x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			if (list->flags[0] == '+' && (int)x >= 0)
			{
					ft_putchar_cow('+', list);
					list->widthofline--;
					list->widthofcontent--;
			}
			handling_float(x, 15, 52, list->precision, list);
			list->widthofline -= ft_len_of_int(x) + list->precision + 1;
			list->widthofcontent -= ft_len_of_int(x) + list->precision + 1;
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	fF_print_without_minus(t_printf *list, double x)
{
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flags[4] == '0')
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
	if (list->flags[0] == '+' && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	handling_float(x, 15, 52, list->precision, list);

}

void	type_f_and_F(t_printf *list)
{
	double x;

	x = va_arg(list->ap, double);
	if (list->width > ft_len_of_int(x) + list->precision + 1)
		list->widthofline = list->width;
	else
		list->widthofline = ft_len_of_int(x) + list->precision + 1;
	list->widthofcontent = ft_len_of_int(x) + list->precision + 1;
	if (list->flags[0] == '+' && x >= 0)
		list->widthofcontent++;
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		fF_print_with_minus(list, x);
	else
		fF_print_without_minus(list, x);
}
