#include "printf.h"

void	type_p(t_printf *list)
{
	long long a;

	a = va_arg(list->ap, long long);
	ft_putstr_cow("0x", list);
	ft_putstr_cow(adv_ft_itoa((long long)a, 16, 'b'), list);
}
