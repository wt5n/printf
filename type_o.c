/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:11:50 by hlikely           #+#    #+#             */
/*   Updated: 2020/02/27 17:25:27 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		o_print_with_minus(t_printf *l, long long x, char *t)
{
	while (l->precision > l->len_of_x)
	{
		ft_putchar_cow('0', l);
		l->precision--;
		l->widthofline--;
	}
	if (l->flags[3] == '#' && l->len_of_x > 0 && l->widthofline > 1 && x != 0)
		sharp_x(l);
	if (l->len_of_x > 0 || (l->flags[3] == '#'))
	{
		ft_putstr_cow(t, l);
		l->widthofline -= l->len_of_x;
		l->widthofcontent -= l->len_of_x;
		free(t);
	}
	while (l->widthofline > 0)
	{
		ft_putchar_cow(' ', l);
		l->widthofline--;
	}
}

void		o_presicion_over_len(t_printf *list, long long x, char *t)
{
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flags[3] == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofcontent > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	if (list->len_of_x > 0)
		ft_putstr_cow(t, list);
	free(t);
}

void		o_print_without_minus(t_printf *list, long long x, char *t)
{
	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flags[4] != '0')))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flags[3] == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flags[4] == '0')
			ft_putchar_cow('0', list);
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->len_of_x > 0 || (list->flags[3] == '#'))
		ft_putstr_cow(t, list);
	free(t);
}

static void	one_more_func(t_printf *list, uintmax_t x)
{
	list->len_of_x = lennum_base(x, list->base);
	if (list->precision == 0 && list->np == 'n' && (list->flags[3] != '#'))
		list->len_of_x = 0;
	if ((list->flags[3] == '#') && x != 0)
		list->len_of_x++;
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
}

void		type_o(t_printf *list)
{
	uintmax_t	x;
	char		*t;

	if (ft_strcmp(list->length, "l") == 0)
		x = (unsigned long)va_arg(list->ap, unsigned long int);
	else if (ft_strcmp(list->length, "ll") == 0)
		x = (unsigned long long)va_arg(list->ap, unsigned long long int);
	else if (ft_strcmp(list->length, "hh") == 0)
		x = (unsigned char)va_arg(list->ap, unsigned int);
	else if (ft_strcmp(list->length, "h") == 0)
		x = (unsigned short)va_arg(list->ap, unsigned int);
	else
		x = (unsigned int)va_arg(list->ap, unsigned long int);
	x = (uintmax_t)x;
	if (x == ULONG_MAX)
		t = ft_strdup("1777777777777777777777");
	else
		t = adv_ft_itoa(x, list->base, 'a');
	one_more_func(list, x);
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		o_print_with_minus(list, x, t);
	else if (list->precision > list->len_of_x - 1)
		o_presicion_over_len(list, x, t);
	else
		o_print_without_minus(list, x, t);
}
