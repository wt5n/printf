# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

#include "printf.h"

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
char	*adv_ft_itoa(long long n, int base, char c);
int		lennum(long long n);

char	*full_str(char *str)
{
	int i;
	int	j;
	int len;
	char *res;

	i = 0;
	j = 0;
	len = 10 - ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (11))))
		return (NULL);
	res[10] = '\0';
	while (len > 0)
	{
		res[i] = '0';
		i++;
		len--;
	}
	while (i < 10)
	{
		res[i] = str[j];
		i++;
		j++;
	}
	return (res);
}

void	rounding(unsigned long long *arr, int i, int np)
{
	int 	x;

	x = 1;
	//printf("\nini:%d\n", i);
	if (np > 10)
	{
		np -= 10;
		i++;
	}
	while (np--)
		x *= 10;
	addit(arr, i, x);
	//printf("\nafter :%llu %d\n", arr[i], i);
}

void	ap_number(t_double d1 ,unsigned long long *arr, int countofel, int pow)
{
	int		i;

	i = 0;
	while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }
	addit(arr, countofel - 1, d1.part.m);
	while (pow)
	{
		mult(arr, 0, 5, countofel);
		pow--;
	}
	addit(arr, 9, 100);
	pow = d1.part.e - 1023;
	while (pow)
	{
		mult(arr, 0, 2, countofel);
		pow--;
	}
}

int		handling_float(double d, int countofel, int pow, int p, t_printf *list)
{
	t_double 			d1;
	unsigned long long 	*arr;
	int 				i;
	char 				*tmp;
	int 				n;
	int 				iszero;

	iszero = 0;
	n = 98;
	i = 0;
	if ((int)d == 0)
	{
		d += 1;
		iszero = 1;
	}
	d1.d = d;
	//printf("m:%llu e:%llu\n", d1.part.m, d1.part.e);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
	ap_number(d1, arr, countofel, pow);
	/*
	int j;
	i = 0;
	while (i < countofel)
    {
		j = lennum(arr[i]);
		while (j < 10)
		{
			printf("0");
			j++;
		}
        printf("%I64d", arr[i]);
        i++;
    }
	printf("\n");
	*/
	i = 0;
	while (arr[i] == 0 && n > 10)
	{
		i++;
		n -= 10;
	}
	if (p)
		rounding(arr, i, n + p + 1);
	//printf("n:%d\n", n);
	//printf("\nouti:%d\n", i);
	tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
	//printf("tmp:%s\n", tmp);
	while (*tmp == '0')
	{
		tmp++;
		n--;
	}
	if (iszero)
	{
		ft_putchar_cow('0', list);
		n--;
		tmp++;
	}
	//printf("%s\n", tmp);
	if (d1.part.s)
		ft_putchar_cow('-', list);
	while (n--)
		ft_putchar_cow(*tmp++, list);
	//printf("\nbefore:%llu %d\n", arr[i], i);
	if (p)
		ft_putchar_cow('.', list);
	while (p--)
	{
		if (!*tmp)
		{
			i++;
			tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
		}
		ft_putchar_cow(*tmp++, list);
	}
	return (0);
}
