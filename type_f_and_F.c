#include "printf.h"

static void	f_print_with_minus1(t_printf *list, double x)
{
	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	if (list->len_of_x > 0)
	{
		handling_float(x, 15, 52, list);
		list->widthofline -= list->len_of_x;
		list->widthofcontent -= list->len_of_x;
	}
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void		f_print_with_minus(t_printf *list, double x)
{
	if ((list->flags[0] == '+') && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	if ((list->flags[2] == ' ') && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		if (list->precision > list->len_of_x)
			list->widthofline--;
	}
	if (list->len_of_x > 0)
		list->len_of_x = ft_len_of_int(x);
	f_print_with_minus1(list, x);
}

static void	f_presicion_over_len1(t_printf *list, double x)
{
	if (x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		list->widthofline--;
	}
	while (list->widthofcontent > ft_len_of_int(x))
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	handling_float(x, 15, 52, list);
}

void		f_presicion_over_len(t_printf *list, double x)
{
	if (list->width > list->precision && (int)x < 0)
		list->widthofline--;
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((list->flags[0] == '+') && x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	f_presicion_over_len1(list, x);
}

static void	f_print_without_minus1(t_printf *list, double x)
{
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flags[4] == '0')
		{
			if (x < 0)
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

	handling_float(x, 15, 52, list);
}

void		f_print_without_minus(t_printf *list, double x)
{
	if ((list->flags[2] == ' ') && list->widthofcontent >= list->len_of_x && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofline > list->widthofcontent && \
		//((list->precision < list->len_of_x && list->np == 'n') || 
		(list->flags[4] != '0'))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((list->flags[0] == '+') && x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	f_print_without_minus1(list, x);
}

static void	partofthesystem(t_printf *list, double x)
{
	if (list->flags[0] == '+' && list->flags[2] == ' ')
		list->flags[2] = '\0';
		/*
	if (list->precision == 0 && list->np == 'n')
		//list->len_of_x = 0;
		list->len_of_x = 1;
	*/
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision > list->len_of_x && list->precision > list->width)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}
	/*
	if (list->precision < list->len_of_x)
		list->widthofcontent = list->len_of_x;
	else
		list->widthofcontent = list->precision;
	*/
	list->widthofcontent = list->len_of_x;
	if (list->flags[0] == '+' && x >= 0)
	{
		if (list->np == 'n' && list->precision > 0)
			list->widthofcontent++;
		else if (list->widthofline > list->widthofcontent)
			list->widthofcontent++;
	}
}

void	type_f_and_F(t_printf *list)
{

	double	x;

	if (ft_strcmp(list->length, "L") == 0)
		x = (long double)va_arg(list->ap, long double);
	else
		x = va_arg(list->ap, double);

	//handling_float(x, 15, 52, list);

	list->len_of_x = ft_len_of_int(x) + list->precision;	
	partofthesystem(list, x);
	

	if (list->flags[3] == '#' && list->precision == 0)
		list->widthofline--;
	if (list->precision > 0)
	{
		if (list->widthofline == list->widthofcontent)
			list->widthofline++;
		list->widthofcontent++;
		
	}

	while (list->widthofline <= list->widthofcontent && \
	list->flags[2] == ' ' && x >= 0)
		list->widthofline++;

	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		f_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		f_presicion_over_len(list, x);
	else
		f_print_without_minus(list, x);
		
}