/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:02:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/01/23 17:40:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	c_width_minus(t_printf *list, unsigned int c)
{
	ft_putchar_cow(c, list);
	while (list->width > 1)
	{
		ft_putchar_cow(' ', list);
		list->width--;
	}
}

void	c_width(t_printf *list, unsigned int c)
{
	if (list->flag == '-')
		c_width_minus(list, c);
	else
	{
		while (list->width > 1)
		{
			ft_putchar_cow(' ', list);
			list->width--;
		}
		ft_putchar_cow(c, list);
	}
}

void	type_c(t_printf *list)
{
	unsigned int c;

	c = va_arg(list->ap, int);
	if (list->width)
		c_width(list, c);
	else
		ft_putchar_cow(c, list);
}
