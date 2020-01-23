#include "printf.h"

int		ft_strcmp(const char *s1, const char *s2);

long change_length_di(t_printf *list, long long x)
{
	printf("%s\n", list->length);
	if (!ft_strcmp(list->length, "hh"))
		return (signed char)x;
	else if (!ft_strcmp(list->length, "h"))
		return (short)x;
	else if (!ft_strcmp(list->length, "l"))
	{
		x = (long)x;
		printf("in: %ld\n", x);
		return (long)x;
	}
	else if (!ft_strcmp(list->length, "ll"))
	{
		return (long long)x;
	}
}

void change_length_u_x(t_printf *list, long long x)
{
	if (list->length == "hh")
		x = (unsigned char)x;
	else if (list->length == "h")
		x = (unsigned short)x;
	else if (list->length == "l")
		x = (unsigned long)x;
	else if (list->length == "ll")
		x = (unsigned long long)x;
}

void change_length_f_e_a_g(t_printf *list, double x)
{
	if (list->length == "l")
		x = (double)x;
	else if (list->length == "ll")
		x = (long double)x;
}