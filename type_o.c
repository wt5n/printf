#include "printf.h"

void	o_print_with_minus(t_printf *list, long long x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
			list->widthofline -= lennum_base(x, list->base);
			list->widthofcontent -= lennum_base(x, list->base);
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	o_presicion_over_len(t_printf *list, long long x)
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
	ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	o_print_without_minus(t_printf *list, long long x)
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
	ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	sharp_o(t_printf *list)
{
	if (list->flag == '#' && list->type == 'o')
	{
		ft_putchar_cow('0', list);
		list->widthofline--;
	}
	else if (list->flag == '#' && list->type == 'x')
	{
		ft_putstr_cow("0x", list);
		list->widthofline -= 2;
	}
	else if (list->flag == '#' && list->type == 'X')
	{
		ft_putstr_cow("0X", list);
		list->widthofline -= 2;
	}
}

void	type_o(t_printf *list)
{
	long long x;

	x = va_arg(list->ap, long long);
	list->base = 16;
	if (x == 4294967296)
	{
		ft_putchar_cow('0', list);
		return ;
	}
	if (list->width > lennum_base(x, list->base))
		list->widthofline = list->width;
	else
	{
		if (list->precision < lennum_base(x, list->base) && list->precision > 0)
			list->widthofline = list->precision;
		else
			list->widthofline = lennum_base(x, list->base);
	}
	if (list->precision < lennum_base(x, list->base))
		list->widthofcontent = lennum_base(x, list->base);
	else
		list->widthofcontent = list->precision;
	if (list->flag == '#' && x > 0)
		sharp_o(list);
	if (list->precision > lennum_base(x, list->base) - 1)
		o_presicion_over_len(list, x);
	else if ((list->flag == '-') && (list->width > list->widthofcontent))
		o_print_with_minus(list, x);
	else
		o_print_without_minus(list, x);
}