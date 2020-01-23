# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef union s_float {
    float f;
    struct {
    unsigned int m: 23;
    unsigned int e: 8;
    unsigned int s: 1;
    }   part;
}       t_float;

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*minimum(void)
{
	int					i;
	int					n;
	char				*res;

	i = 10;
	n = -2147483648;
	res = (char*)malloc(sizeof(char) * 12);
	if (!res)
		return (NULL);
	res[0] = '-';
	while (i > 0)
	{
		res[i] = (n % 10) * -1 + '0';
		n /= 10;
		i--;
	}
	res[11] = '\0';
	return (res);
}

char	*nole(void)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

size_t	lennum_base(int n, int base)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

char			size_of_letter(char c)
{
	if (c >= 'a')
		return ('a');
	return ('A');
}

char			*adv_ft_itoa(int n, int base, char c)
{
	char	*res;
	size_t	len;
	char	cc;

	cc = size_of_letter(c);
	len = lennum_base(n, base);
	if (len == 0)
		return ("");
	if (n == 0)
		return (nole());
	if (n == -2147483648)
		return (minimum());
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		if (n % base > 9)
			res[len--] = (n % base) + (cc - 10);
		else
			res[len--] = (n % base) + '0';
		n /= base;
	}
	return (res);
}

double ft_pow_float(int a, int b)
{
    int i;
    float res;

    i = a;
    res = a;
    if (b == 0)
        return (1.0);
	if (b == 1)
		return (a);
    if (b > 0)
    {
        b--;
        while (b--)
            res = res * i;
    }
    else
        res = 1 / ft_pow_float(a, b * -1);
    return (res);
}

void    in_arr(unsigned long long a, unsigned long long b, unsigned long long *arr, int i, unsigned long long buf)
{
    unsigned long long res;
    unsigned long long tmp;
    int tmp_i;

    tmp_i = i - 1;
    res = a % 10000 + b % 10000;
    printf("a b sum:%llu %llu %llu\n", a % 10000, b % 10000, a % 10000 + b % 10000);
    buf = res / 10000;
    printf("over:%llu\n", res / 10000);
    tmp = arr[i] + res;
    if (res > 9999)
    {
        in_arr(arr[tmp_i], res / 10000, arr, tmp_i, buf);
    }

	if (tmp > 9999)
    {
        in_arr(0, tmp / 10000, arr, tmp_i, buf);
    }

	arr[i] = tmp % 10000;
    if (a / 10000 > 0 || b / 10000 > 0)
	{
        in_arr(a / 10000, b / 10000, arr, tmp_i, buf);
	}
	printf("arr[%d]:%llu\n", i, arr[i]);

}

char	*full_mantissa(char *str)
{
	int i;
	int	j;
	int len;
	int len2;
	char *res;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	len2 = 0;
	while (len2 + len < 23)
		len2++;
	if (!(res = (char*)malloc(sizeof(char) * (25))))
		return (NULL);
	res[24] = '\0';
	res[i] = '1';
	i++;
	//if (len2 > 0)
	//	res[i++] = '1';
	while (len2 > 0)
	{
		res[i] = '0';
		i++;
		len2--;
	}
	while (len--)
	{
		res[i] = str[j];
		i++;
		j++;
	}
	printf("\n%s\n", res);
	return (res);
}

int		main(void)
{
	unsigned long long *arr;
    int i;
	t_float d1;
	float f;
	char *bits;
	int e;
	//int m;
	int power;

	f = 236565.15435357625;
	f = 123456789;
	//f = 12345678;
    i = 0;
    arr = (unsigned long long*)malloc(sizeof(unsigned long long) * 8);
    while (i < 8)
    {
        arr[i] = 0;
        i++;
    }
	d1.f = f;
	printf("m:%d e:%d\n", d1.part.m, d1.part.e);
	bits = full_mantissa(adv_ft_itoa(d1.part.m, 2, 'c'));
	e = d1.part.e - 127;
	// power is equal presicion
	power = 0;
	printf("\n%d %d\n", e, power);
	while (*bits)
	{

		if (((unsigned long long)((*bits - 48) * ft_pow_float(2, e))) * (unsigned long long)ft_pow_float(10, power) > 0)
		{
			printf("bit:%llu\n", ((unsigned long long)((*bits - 48) * ft_pow_float(2, e))) * (unsigned long long)ft_pow_float(10, power));
			in_arr(0, ((unsigned long long)((*bits - 48) * ft_pow_float(2, e))), arr, 7, 0);
		}
		e--;
		bits++;
	}
	i = 0;
	printf("answer is:");
	while (i < 8)
    {
        printf("%llu", arr[i]);
        i++;
    }
	/*
	while (i < 8)
    {
		if (i == 4 - power / 4)
		{
			printf("%llu.", arr[i] / (int)ft_pow_float(10, power % 4));
			if (arr[i] % (int)ft_pow_float(10, power % 4) > 0)
				printf("%llu", arr[i] % (int)ft_pow_float(10, power % 4));
		}
		else
        	printf("%llu", arr[i]);
        i++;
    }
	*/
	printf("\n");
	return (0);
}
