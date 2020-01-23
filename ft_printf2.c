/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:45:26 by ksenaida          #+#    #+#             */
/*   Updated: 2020/01/21 03:54:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_cow(char c, t_printf *list)
{
	write(1, &c, 1);
	list->cow++;
}

void	ft_putstr_cow(char const *s, t_printf *list)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
	list->cow += i;
}

int		ft_printf(char *format, ...)
{
	t_printf	*list;
	va_list	ap;
	va_start(ap, format);
	unsigned	int ux;
	long long		lx;
	double			fx;
	char			*s;
	int				cow;

	cow = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list = newlist_with_printf();
			format = flag(format, list);
			//printf("%c %lu %lu %s %c\n", list->flag, list->width, list->presicion, list->length, list->type);
			if (list->type == 'c')
			{
				ux = va_arg(ap, int);
				type_c(list, ux);
			}

			else if (list->type == 's' || list->type == 'S')
			{
				s = va_arg(ap, char*);
				if (s == 0)
					ft_putstr_cow("(null)", list);
				else
					str(list, s);
			}
			else if (list->type == 'd' || list->type == 'i')
			{
				lx = va_arg(ap, long long);
				if (ft_strcmp(list->length, "Q"))
				{
					lx = change_length_di(list, lx);
					printf("after:%ld\n", lx);
				}
				d_and_i(list, lx);
			}
			else if (list->type == 'u')
			{
				lx = va_arg(ap, long long);
				type_u(list, lx);
			}
			else if (list->type == 'x' || list->type == 'X' || list->type == 'o')
			{
				lx = va_arg(ap, long long);
				type_x_and_X(list, lx);
			}
			else if (list->type == 'f' || list->type == 'F')
			{
				fx = va_arg(ap, double);
				type_f_and_F(list, fx);
			}
			else if(list->type == 'p')
			{
				s = va_arg(ap, char*);
				type_p(list, s);
			}
			else if (*format == '%')
			{
				ft_putchar(*format);
				cow++;
			}
			cow += list->cow;
		}
		else
		{
			ft_putchar(*format);
			cow++;
		}
		format++;
	}
	//printf("%c %i %i %s %c", list->flag, list->width, list->presicion, list->length, list->type);
	va_end (ap);
	return (cow);
}
