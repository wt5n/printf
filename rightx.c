#include "printf.h"

void	sharp_x(t_printf *list)
{
	if (list->flag == '#' && list->type == 'o')
	{
		ft_putchar_cow('0', list);
		list->widthofline--;
	}
	else if (list->flag == '#' && list->type == 'x')
	{
		ft_putstr_cow("0x", list);
		if (list->widthofline > 2 && list->widthofline > list->widthofcontent + 1)
			list->widthofline -= 2;
	}
	else if (list->flag == '#' && list->type == 'X')
	{
		ft_putstr_cow("0X", list);
		if (list->widthofline > 2 && list->widthofline > list->widthofcontent + 1)
			list->widthofline -= 2;
	}
}

void	x_print_with_minus(t_printf *list, long long x)
{
	/*
	if (list->flag == '#' && list->len_of_x > 0 && list->widthofline > 1  && \
		//list->widthofline > list->len_of_x + 1 &&
		//(list->flag2 != '0') &&
		//if (list->width < list->len_of_x && )
		x != 0 \
		)
		list->widthofline -= 2;
	*/
	/*
	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flag != '0' && list->flag2 != '0')))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	*/
	if (list->flag == '#' && list->len_of_x > 0 && list->widthofline > 1 && x != 0)
		sharp_x(list);
	if (list->len_of_x > 0)
		list->len_of_x = lennum_base(x, list->base);

	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	if (list->len_of_x > 0)
	{
		//zamenit
		ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
		list->widthofline -= lennum_base(x, list->base);
		list->widthofcontent -= lennum_base(x, list->base);
	}
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	x_presicion_over_len(t_printf *list, long long x)
{
	if (list->flag == '#' && list->len_of_x > 0 && x != 0)
		list->widthofline -= 2;
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flag == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofcontent > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	x_print_without_minus(t_printf *list, long long x)
{
	if (list->flag == '#' && list->len_of_x > 0 && list->widthofline > 1  && \
		//list->widthofline > list->len_of_x + 1 &&
		//(list->flag2 != '0') &&
		//if (list->width < list->len_of_x && )
		x != 0 \
		)
		list->widthofline -= 2;

	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flag != '0' && list->flag2 != '0')))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flag == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flag == '0' || list->flag2 == '0')
			ft_putchar_cow('0', list);
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}

	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	type_x_and_X(t_printf *list)
{
	long long x;

	x = va_arg(list->ap, long long);
	list->base = 16;
	list->len_of_x = lennum_base(x, list->base);
	if (list->precision == 0 && list->np == 'n')
		list->len_of_x = 0;
	if (x == 4294967296)
	{
		ft_putchar_cow('0', list);
		return ;
	}
	if ( list->len_of_x > 0 && list->len_of_x != 0 && list->len_of_x + 2 > list->width && \
		(list->flag == '#' || list->flag2 == '#') && x != 0)
		list->widthofline =list->len_of_x + 2;
	else if (list->width > list->len_of_x)
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
	if ((list->flag == '-' || list->flag2 == '-') && (list->width > list->widthofcontent))
		x_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		x_presicion_over_len(list, x);
	else
		x_print_without_minus(list, x);
}
