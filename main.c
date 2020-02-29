#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;

	printf("\n");


	//cow = printf("{%Lf}", 678.123456L);
	//cow = printf("%s", "asd");
	//cow = printf("%f\n", NULL);

	//printf("\n");

	//cow2 = ft_printf("%s\n", "asd");
	//cow2 = ft_printf("%c\n", 'a');
	//cow2 = ft_printf("%-d\n", 456);
	//cow2 = ft_printf("%#x\n", 456);
	//cow2 = ft_printf("%#o\n", 456);
	//cow2 = ft_printf("%u\n", 456);
	cow2 = ft_printf("%f", NULL);
	//cow2 = ft_printf("%f\n", 1.0);
	//cow2 = ft_printf("%f\n", 0.0);
	//cow2 = ft_printf("%f\n", 0.000456);
	//cow2 = ft_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);

	printf("\ncow :%d\ncow2:%d\n", cow, cow2);

	return (0);
}
//anton_hiiii_it's_sonya
