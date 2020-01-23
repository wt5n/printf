#include "printf.h"

void	type_p(t_printf *list)
{
	char *a;

	a = &(list->f_copy);
	type_x_and_X(list);
}
