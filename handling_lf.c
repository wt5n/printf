/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_lf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:02:28 by hlikely           #+#    #+#             */
/*   Updated: 2020/02/28 18:00:31 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int		lennum2(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

void	ap_number_lf(t_double_1 d1, unsigned long long *arr, int countofel, int pow)
{
	int		i;

	i = 0;
	while (i < countofel)
		arr[i++] = 0;
	addit(arr, countofel - 1, d1.part1.m);
	while (pow--)
		mult(arr, 0, 5, countofel);
	addit(arr, 10, 1000);
	//pow = d1.part1.e - 16383;
	if (pow > 0)
		while (pow--)
			mult(arr, 0, 2, countofel);
	else
	{
		while (pow < 0)
		{
			mult(arr, 0, 5, countofel);
			pow++;
		}
		while (pow++ < ((d1.part1.e - 16383) * -1))
			divis(arr, 15, 10);
	}
    int j;
	i = 0;
	while (i < countofel)
    {
		j = lennum2(arr[i]);
		while (j < 10)
		{
			printf("0");
			j++;
		}
        printf("%llu", arr[i]);
        i++;
    }
}

void	handling_lfloat_1(t_printf *list, char *tmp, long long n, int s)
{
	while (*tmp == '0' && n > 1)
	{
		tmp++;
		n--;
	}
	if (((list->precision == 0 && list->np == 'n') || list->precision))
		rounding(tmp, list->precision + n);
	if (s)
		ft_putchar_cow('-', list);
	while (n--)
		ft_putchar_cow(*tmp++, list);
	if (list->precision || list->flags[3] == '#')
		ft_putchar_cow('.', list);
	while (list->precision--)
		ft_putchar_cow(*tmp++, list);
}

void	handling_float_lf(long double d, int countofel, int pow, t_printf *list)
{
	t_double_1			d1;
	unsigned long long	*arr;
	int					i;
	char				*tmp;
	long long			n;

	n = 86;
	i = 0;
	d1.ld = d;
    printf("m:%llu\n", d1.part1.m);
    printf("e:%llu\n", d1.part1.e);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
	ap_number_lf(d1, arr, countofel, pow);
	i = 0;
	while (arr[i] == 0 && n > 10)
	{
		i++;
		n -= 10;
	}
	tmp = full_str(arr, i);
	handling_lfloat_1(list, tmp, n, d1.part1.s);
	free(arr);
	free(tmp);
}
