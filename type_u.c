#include "printf.h"

void	u_print_with_minus(t_printf *list, long long x)
{
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
}

void	u_presicion_over_len(t_printf *list, long long x)
{
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofcontent > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
}

void	u_print_without_minus(t_printf *list, long long x)
{
	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flags[4] != '0' )))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flags[4] == '0')
			ft_putchar_cow('0', list);
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
}

void	type_u(t_printf *list)
{
	uintmax_t x;

	if (ft_strcmp(list->length,"l") == 0)
		x = (unsigned long)va_arg(list->ap, unsigned long int);
	else if (ft_strcmp(list->length,"ll") == 0)
		x = (unsigned long long)va_arg(list->ap, unsigned long long int);
	else if (ft_strcmp(list->length,"hh") == 0)
		x = (unsigned char)va_arg(list->ap, unsigned int);
	else if (ft_strcmp(list->length,"h") == 0)
		x = (unsigned short)va_arg(list->ap, unsigned int);
	else
		x = (unsigned int)va_arg(list->ap, unsigned long int);

	x = (uintmax_t)x;

	list->len_of_x = ft_len_of_int(x);
	if (list->precision == 0 && list->np == 'n')
		list->len_of_x = 0;

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

	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		u_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		u_presicion_over_len(list, x);
	else
		u_print_without_minus(list, x);
}
