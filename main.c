#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;


	printf("\n");
	cow = printf("%#037lx", 22337203685477ul);


	printf("\n");


	cow2 = ft_printf("%#037lx", 22337203685477ul);



	printf("\ncow :%d\ncow2:%d\n", cow, cow2);

	return (0);
}
