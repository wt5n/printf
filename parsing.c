/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/02/19 20:54:10 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*t_printf	*flag(t_printf *list)
{
	if (list->f_copy[list->i] == '+')
	{
		list->flag = '+';
		if (list->f_copy[list->i + 1] == '0')
			list->flag2 = '0';
		if (list->f_copy[list->i + 1] == '-')
			list->flag2 = '-';
	}
	if (list->f_copy[list->i] == '-')
		list->flag = '-';
	if (list->f_copy[list->i] == '#')
		list->flag = '#';
	if (list->f_copy[list->i] == '0')
	{
		list->flag = '0';
		//flag '0' is ignored when flag '-' is present
		if (list->f_copy[list->i + 1] == '-')
		{
			list->flag = '-';
			list->i++;
		}
		if (list->f_copy[list->i + 1] == '+')
			list->flag2 = '+';
	}
	if (list->f_copy[list->i] == ' ')
		list->flag = ' ';
	if (list->flag != 'Q')
		list->i++;
	if (list->flag2 != 'Q')
		list->i++;
	return (width(list));
}*/

t_printf	*flag(t_printf *list)
{
	char	fff[5] = "QQQQ\0";
	int		i;
	int		x;
	int		j;
	
	x = 0;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (list->cons[i] == list->f_copy[list->i])
			{
				fff[x] = list->cons[i];
				x++;
				list->i++;
			}
			i++;
		}
		j++;
	}
	if (fff[0] == ' ' && fff[1] == '0' && fff[2] == '+' && fff[3] == '-')
	{
		list->flag = '+';
		list->flag2 = '-';
	}
	if (fff[0] == '0' && fff[1] == '+' && fff[2] == '-')
	{
		list->flag = '+';
		list->flag2 = '-';
	}
	else if (fff[0] == ' ' && fff[1] == '+' && fff[2] == '0')
	{
		list->flag = '+';
		list->flag2 = '0';
	}
	else if (fff[0] == ' ' && fff[1] == '+' && fff[2] == '-')
	{
		list->flag = '+';
		list->flag2 = '-';
	}
	else if (fff[0] == ' ' && fff[1] == '0' && fff[2] == '-')
	{
		list->flag = ' ';
		list->flag2 = '-';
	}
	else if (fff[0] == ' ' && fff[1] == '0' && fff[2] == '+')
	{
		list->flag = '0';
		list->flag2 = '+';
	}
	else if (fff[0] == ' ' && fff[1] == '0' && fff[2] == '+')
	{
		list->flag = '0';
		list->flag2 = '+';
	}
	else if (fff[0] == '0' && fff[1] == '-')
		list->flag = '-';
	else if (fff[0] == ' ' && fff[1] == '+')
		list->flag = '+';
	else
	{
		list->flag = fff[0];
		list->flag2 = fff[1];
	}
	return (width(list));
}

t_printf	*width(t_printf *list)
{
	/*
	while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		list->width *= 10;
		list->width += (list->f_copy[list->i] - 48);
		list->i++;
	}
	*/
	int	num;
	
	if (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		num = ft_atoi(&list->f_copy[list->i]);
		list->width = num;
		while (num > 0)
		{
			list->i++;
			num /= 10;
		}
	}
	else
		list->nw = 'y';
	
	return (precision(list));
}

t_printf	*precision(t_printf *list)
{
	if (list->f_copy[list->i] == '.')
	{
		list->i++;
		//list->precision = 0;
		while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
		{
			list->precision *= 10;
			list->precision += (list->f_copy[list->i] - 48);
			list->i++;
		}
	}
	else 
		list->np = 'y';
	
	return (length(list));
}

t_printf	*length(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->args[i] != '\0')
	{
		if (list->args[i] == list->f_copy[list->i])
		{
			list->length[0] = list->f_copy[list->i];
			list->i++;
			if (list->f_copy[list->i] == list->length[0])
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
