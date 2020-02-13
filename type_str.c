/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:34:15 by ksenaida          #+#    #+#             */
/*   Updated: 2020/02/13 20:27:01 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	str_print_with_minus(t_printf *list, char *str)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putchar_cow(*str, list);
			str++;
			list->widthofline--;
			list->widthofcontent--;
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	str_print_without_minus(t_printf *list, char *str)
{
	while (list->widthofline > 0)
	{
		while (list->widthofline > list->widthofcontent)
		{
			ft_putchar_cow(' ', list);
			list->widthofline--;
		}
		if (list->widthofline > 0)
		{
			ft_putchar_cow(*str, list);
			str++;
			list->widthofline--;
		}
	}
}

void	type_s(t_printf *list)
{
	char *	str;

	str = va_arg(list->ap, char*);
	if (str == 0)
		ft_putstr_cow("(null)", list);
	else
	{
		if (list->width > ft_strlen(str))
			list->widthofline = list->width;
		else if (list->width < ft_strlen(str) && list->nw == 'n' && \
				list->precision < ft_strlen(str) && list->np == 'n')
			list->widthofline = list->width;
		else if (list->width < ft_strlen(str) && list->nw == 'n')
		{
			list->widthofline = ft_strlen(str);
			/*
			if (list->precision < ft_strlen(str) && list->precision > 0)
				list->widthofline = list->precision;
			else
				list->widthofline = ft_strlen(str);
			*/
		}
		else if (list->precision < ft_strlen(str) && list->np == 'n')
			list->widthofline = list->precision;
		else
			list->widthofline = ft_strlen(str);
		
		if (list->nw == 'y' && list->precision == 0 && list->np == 'n')
		{
			list->widthofcontent = 0;
			list->widthofline = 0;
		}
		else if (list->precision == 0 && list->np == 'n')
			list->widthofcontent = 0;
		else if (list->precision < ft_strlen(str) && list->np == 'n')
			list->widthofcontent = list->precision;
		else 
			list->widthofcontent = ft_strlen(str);
		if ((list->flag == '-') && (list->width > list->widthofcontent))
			str_print_with_minus(list, str);
		else
			str_print_without_minus(list, str);
	}
}
