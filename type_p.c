#include "printf.h"
#include <limits.h>

static t_printf		*print_u(t_printf *list, char *str)
{
	size_t		not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	list->cow += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flags[1] != '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	write(1, "0x", 2);
	display_gap(list, '0', (list->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (list->flags[1] == '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	free(str);
	return (list);
}

void	type_p(t_printf *list)
{
	char		*str;
	uintmax_t	a;

	a = (unsigned long)(va_arg(list->ap, unsigned long int));
	a = (uintmax_t)a;
	if (!(str = adv_ft_itoa(a, 16, 'a')))
		exit(-1);
	if (list->precision == 0 && a == 0)
		*str = '0';
	if (list->flags[4] == '0' && list->np == 'y' && !list->flags[1])
	{
		list->precision = list->width - 2;
		list->width = 0;
	}
	print_u(list, str);
	// ft_putstr_cow("0x", list);
	// ft_putstr_cow(adv_ft_itoa((long long)a, 16, 'b'), list);
}
