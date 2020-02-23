#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;

	printf("\n");


	cow = printf("%.4f", 0.0894255);

	printf("\n");

	cow2 = ft_printf("%.4f", 0.0894255);

	printf("\ncow :%d\ncow2:%d\n", cow, cow2);

	return (0);
}
//anton_hiiii_it's_sonya