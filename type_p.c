/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:00:21 by hlikely           #+#    #+#             */
/*   Updated: 2020/02/24 15:15:06 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

void	type_p(t_printf *list)
{
	char		*str;
	uintmax_t	a;

	a = (unsigned long)(va_arg(list->ap, unsigned long int));
	a = (uintmax_t)a;
	if (!(str = adv_ft_itoa(a, 16, 'a')))
		exit(-1);
	if (list->precision == 0 && a == 0)
		*str = '0';
	if (list->flags[4] == '0' && list->np == 'y' && !list->flags[1])
	{
		list->precision = list->width - 2;
		list->width = 0;
	}
	list->len_of_x = ft_strlen(str) + 2;
	list->cow += (list->len_of_x <= list->width) ? list->width : list->len_of_x;
	if (list->flags[1] != '-')
		display_gap(list, ' ', list->width - list->len_of_x, 0);
	write(1, "0x", 2);
	display_gap(list, '0', (list->precision - list->len_of_x) + 2, 1);
	ft_putstr(str);
	if (list->flags[1] == '-')
		display_gap(list, ' ', list->width - list->len_of_x, 0);
	free(str);
}
