/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/01/23 17:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	*flag(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->cons[i] != '\0')
	{
		while (list->cons[i] == list->f_copy[list->i])
		{
			while (list->f_copy[list->i] == '+')
				list->flag = '+';
			while (list->f_copy[list->i] == '-')
				list->flag = '-';
			while (list->f_copy[list->i] == '#')
				list->flag = '#';
			while (list->f_copy[list->i] == '0')
				list->flag = '0';
			while (list->f_copy[list->i] == ' ')
				list->flag = ' ';
			i = 0;
		}
		i++;
	}
	return (width(list));
}

t_printf	*width(t_printf *list)
{
	while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		list->width *= 10;
		list->width += (list->f_copy[list->i] - 48);
		list->i++;
	}
	return (precision(list));
}

t_printf	*precision(t_printf *list)
{
	while (list->f_copy[list->i] == '.')
	{
		list->i++;
		list->precision = 0;
	}
	while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		list->precision *= 10;
		list->precision += (list->f_copy[list->i] - 48);
		list->i++;
	}
		//list->np = 'y';
	return (length(list));
}

t_printf	*length(t_printf *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (list->args[i] != '\0')
	{
		while (list->args[i] == list->f_copy[list->i])
		{
			list->length[j] = list->f_copy[list->i];
			list->length[j + 1] = '\0';
			list->i++;
			j++;
		}
		i++;
	}
	return (type(list));
}

t_printf	*type(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->specs[i] != '\0')
	{
		if (list->specs[i] == list->f_copy[list->i])
			list->type = list->specs[i];
		i++;
	}
	return (list);

	/*if (format[0] == 'd' || format[0] == 'i' || format[0] == 'u' || format[0] == 'f' || format[0] == 'F' || \
		format[0] == 'e' || format[0] == 'E' || format[0] == 'g' || format[0] == 'G' || format[0] == 'x' || \
		format[0] == 'X' || format[0] == 'o' || format[0] == 's' || format[0] == 'c' || format[0] == 'p' || \
		format[0] == 'a' || format[0] == 'A' || format[0] == 'n')
	{
		list->type = format[0];
	}
	if (format[0] == 'x' || format[0] == 'X')
		list->base = 16;
	if (format[0] == 'o')
		list->base = 8;
	if (list->np == 'y' && (list->type == 'f' || list->type == 'F'))
		list->presicion = 6;
	return (format);*/
}
