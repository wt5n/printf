# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

#include "printf.h"

void	divis(unsigned long long *arr, int i, int num)
{
	unsigned long long res;
	unsigned long long cell;
	unsigned long long x;
	int end;

	x = 10000000000;
	end = i;
	res = 0;
	i = 0;
	while (arr[i] == 0 && i < end)
		i++;
	cell = arr[i];
	while (i <= end)
	{
		res = (cell / num);
		cell = ((arr[i] % num) * x) + arr[i + 1];
		arr[i] = res;
		i++;
	}
}

int		findfirstel(unsigned long long *arr, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (arr[i] != 0)
			return (i);
		i++;
	}
	return (end);
}

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

int		withnull(char *str, char *res, int len, int x)
{
	int		j;
	int		ch;

	j = 0;
	ch = 10 - len;
	while (len-- > 0)
	{
		res[x] = '0';
		x++;
	}
	while (0 < ch--)
	{
		res[x] = str[j];
		x++;
		j++;
	}
	return (x);
}


char	*full_str2(unsigned long long *arr, int i)
{
	int		x;
	int		j;
	int 	len;
	char 	*res;
	char	*str;
	int		totallen;

	x = 0;
	totallen = (15 - i) * 10;
	if (!(res = (char*)malloc(sizeof(char) * (totallen) + 1)))
		return (NULL);
	res[totallen] = '\0';
	while (i < 15)
	{
		str = adv_ft_itoa(arr[i], 10, 'a');
		//printf("str:%s\n", str);
		len = 10 - ft_strlen(str);
		if (len)
			x = withnull(str, res, len, x);
		else
		{
			j = 0;
			while (j < 10)
			{
				res[x] = str[j];
				x++;
				j++;
			}
		}
		i++;
	}
	//printf("%s\n", res);
	return (res);
}

void	rounding(unsigned long long *arr, int i, int np)
{
	int 	x;

	x = 1;
	//printf("\nbefore :%llu %d\n", arr[i], i);
	//printf("ini:%d\n", i);
	if (np > 10)
	{
		np -= 10;
		i++;
	}
	while (np--)
		x *= 10;
	addit(arr, i, x);
	//printf("after :%llu %d\n", arr[i], i);
}

void	rounding2(unsigned long long *arr, int i, int precision)
{
	printf("incoming i:%d\n", i);
	i++;
	printf("j:%llu\n", arr[i]);
	//while (i < 10)
	//{
	printf("i:%llu", arr[i]);
	int delim = 10 * precision;
	delim = 1000000000;
	printf("%llu", arr[i] / delim);
	//	i++;
	//}
	printf("\n");
	while (arr[i] >= 5)
	{
		while (i < 10)
		{
			arr[i] = 0;
			arr[i+1] += 1;
			i++;
		}
		i = 0;
	}
}


void	rounding3(char *tmp, int p)
{
	while (tmp[p] - 48 >= 5)
	{
		tmp[p] = '0';
		p--;
		tmp[p]++;
	}
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
	//printf("pow2:%d\n", pow);
	if (pow > 0)
	{
		while (pow)
		{
			mult(arr, 0, 2, countofel);
			pow--;
		}
	}
	else
	{
		while (pow < 0)
		{
			mult(arr, 0, 5, countofel);
			pow++;
		}
		
		while (pow < ((d1.part.e - 1023) * -1))
		{
			divis(arr, 15, 10);
			pow++;
		}
		
	}
}

char	*handling_float(double d, int countofel, int pow, t_printf *list)
{
	t_double 			d1;
	unsigned long long 	*arr;
	int 				i;
	char 				*tmp;
	int 				n;
	int 				iszero;
	int					lessone;

	iszero = 0;
	lessone = 0;
	n = 98;
	i = 0;
	if (d < 1)
	{
		lessone = 1;
	}
	if (d == 0)
	{
		d += 1;
		iszero = 1;
	}
	d1.d = d;
	//printf("m:%llu e:%llu\n", d1.part.m, d1.part.e);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
	ap_number(d1, arr, countofel, pow);
/*
	//int j;
	i = 0;
	while (i < countofel)
    {
		
		j = lennum(arr[i]);
		while (j < 10)
		{
			printf("0");
			j++;
		}
		
        printf("%llu", arr[i]);
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
	//printf("n:%d\n", n);
	//printf("\nouti:%d\n", i);
	//tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
	tmp = full_str2(arr, i);
	//printf("tmp:%s\n", tmp);
	while (*tmp == '0' && n > 1)
	{
		tmp++;
		n--;
	}
	/*
	if (lessone)
	{
		ft_putchar_cow('0', list);
		tmp++;
	}
	*/
/*
	if (iszero)
	{
		ft_putchar_cow('0', list);
		n--;
		tmp++;
	}
	*/
	//printf("%s\n", tmp);
	if (d1.part.s)
		ft_putchar_cow('-', list);
	while (n--)
		ft_putchar_cow(*tmp++, list);
	//printf("\nbefore:%llu %d\n", arr[i], i);
	if (list->precision)
	{
		ft_putchar_cow('.', list);
		rounding3(tmp, list->precision + 1);
	}
	while (list->precision--)
		ft_putchar_cow(*tmp++, list);
	return (tmp);
}
