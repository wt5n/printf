#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

int		init(t_printf *list)
{
	if (ft_strcmp(list->f_copy, "%") == 0)
		return (0);
	while (list->f_copy[list->i] != '\0')
	{
		if (list->f_copy[list->i] == '%')
		{
			null_struct(list);
			list->i++;
			flag(list);
			display(list);
		}
		else
		{
			write(1, &list->f_copy[list->i], 1);
			list->cow++;
		}
		list->i++;
	}
	return (list->cow);
}

t_printf	*null_struct(t_printf *list)
{
	//всё обнулить
	return (list);
}

t_printf	*newlist_with_printf(t_printf *list)
{
	//list->flag = 'Q';
	list->width = 0;
	list->precision = 0;
	list->length = "Q";
	list->type = 'Q';
	list->widthofline = 0;
	list->widthofcontent = 0;
	list->base = 10;
	list->cow = 0;
	list->np = 'n';
	list->i = 0;
	list->specs = "aAcCeEgGsSnpdDifFuUoxX%";
	list->cons = "-+ 0#";
	list->args = "lhjz";
	return (list);
}

t_printf	*display(t_printf *list)
{
	char	*type;

	type = &list->type;
	if (*type == 'd' || *type == 'i' || *type == 'D')
		d_and_i(list);
	else if (*type == 'c' || *type == 'C')
		type_c(list);
	//else if (*type == 'a' || *type == 'A')
		//type_c(list);
	else if (*type == 'f' || *type == 'F')
		type_f_and_F(list);
	//else if (*type == 'g' || *type == 'G')
		//type_c(list);
	else if (*type == 's' || *type == 'S')
		type_s(list);
	else if (*type == 'u' || *type == 'U')
		type_u(list);
	else if (*type == 'x' || *type == 'X' || *type == 'o')
		type_x_and_X(list);
	else if (*type == 'p')
		type_p(list);
	else
		display_other(list);
	return (list);
}

int		ft_printf(const char *format, ...)
{
	t_printf *list;

	if (!(list = (t_printf*)malloc(sizeof(t_printf))))
		return(-1);
	list->format = format;
	list = newlist_with_printf(list);
	if (format)
	{
		va_start(list->ap, format);
		list->f_copy = (char *)list->format;
		list->cow = init(list);
		va_end(list->ap);
	}
	free(list);
	return (list->cow);
}
