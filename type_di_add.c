/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:07:22 by hlikely           #+#    #+#             */
/*   Updated: 2020/02/24 21:09:56 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

static void	one_more_func(t_printf *list, long long x)
{
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

void		di_print_with_minus(t_printf *list, long long x)
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
	one_more_func(list, x);
}

static void	one_more_func1(t_printf *list, long long x)
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
	if (list->len_of_x > 0)
		ft_putstr_cow(adv_ft_itoa(x, 10, 'a'), list);
}

void		presicion_over_len(t_printf *list, long long x)
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
	one_more_func1(list, x);
}