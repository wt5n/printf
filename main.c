#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;

	printf("\n");


	cow = printf("%hhx", ush_pos_1, ul_pos_1, uch_pos_1);

	printf("\n");


	cow2 = ft_printf("%hhx", ush_pos_1, ul_pos_1, uch_pos_1);

	printf("\ncow :%d\ncow2:%d\n", cow, cow2);

	return (0);
}
