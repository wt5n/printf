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
