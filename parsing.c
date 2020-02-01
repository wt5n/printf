/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/02/01 20:40:13 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	*flag(t_printf *list)
{
	if (list->f_copy[list->i] == '+')
		list->flag = '+';
	if (list->f_copy[list->i] == '-')
		list->flag = '-';
	if (list->f_copy[list->i] == '#')
		list->flag = '#';
	if (list->f_copy[list->i] == '0')
		list->flag = '0';
	if (list->f_copy[list->i] == ' ')
		list->flag = ' ';
	if (list->flag != 'Q')
		list->i++;
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
	if (list->f_copy[list->i] == '.')
	{
		list->i++;
		list->precision = 0;
	}
	else 
		list->np = 'y';
	while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		list->precision *= 10;
		list->precision += (list->f_copy[list->i] - 48);
		list->i++;
	}
	return (length(list));
}

t_printf	*length(t_printf *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list->args[i] != '\0')
	{
		if (list->args[i] == list->f_copy[list->i])
		{
			list->length[0] = list->f_copy[list->i];
			list->i++;
			if (list->f_copy[list->i] == list->length[0]);
			{
				list->length[1] = list->length[0];
				list->i++;
			}
		}
		i++;
	}
	return (type(list));
}

t_printf	*type(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->types[i] != '\0')
	{
		if (list->types[i] == list->f_copy[list->i])
		{
			list->type = list->types[i];
			break ;
		}
		i++;
		if (list->type == 'x' || list->type == 'X')
			list->base = 16;
		if (list->type == 'o')
			list->base = 8;
		if (list->np == 'y' && (list->type == 'f' || list->type == 'F'))
			list->precision = 6;
	}
	return (list);
}
