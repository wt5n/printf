#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;

	printf("\n");


	//cow = printf("{%Lf}", 678.123456L);
	cow = printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);

	printf("\n");

	//cow2 = ft_printf("{%Lf}", 678.123456L);
	cow2 = ft_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);

	printf("\ncow :%d\ncow2:%d\n", cow, cow2);

	return (0);
}
//anton_hiiii_it's_sonya
