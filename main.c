#include "printf.h"
#include <limits.h>

int		main(void)
{
	int cow = 0;
	int cow2 = 0;
	//char c = 'Z';
	//char c2 = 'Z';
	//int	x = 230;
	//float	y = 67890.1234567;
	//float	y = 1.123456789;
	//float y = 0;
	//float y = 123456789123456789;
	//char *str = "hello, world";

/*
	printf(":%c:\n", c);
	printf(":%3c:\n", c);
	printf(":%-3c:\n", c);

	printf("\n");

	ft_printf(":%c:\n", c);
	ft_printf(":%3c:\n", c);
	ft_printf(":%-3c:\n", c);
*/
/*
	printf("\n");

	printf(":%s:\n", str);
	printf(":%10s:\n", str);
	printf(":%.10s:\n", str);
	printf(":%-10s:\n", str);
	printf(":%.15s:\n", str);
	printf(":%15s:\n", str);
	printf(":%-15s:\n", str);
	printf(":%15.10s:\n", str);
	printf(":%-15.10s:\n", str);
	printf(":%-12.20s:\n", str);

	printf("\n");

	ft_printf(":%s:\n", str);
	ft_printf(":%10s:\n", str);
	ft_printf(":%.10s:\n", str);
	ft_printf(":%-10s:\n", str);
	ft_printf(":%.15s:\n", str);
	ft_printf(":%15s:\n", str);
	ft_printf(":%-15s:\n", str);
	ft_printf(":%15.10s:\n", str);
	ft_printf(":%-15.10s:\n", str);
	ft_printf(":%-12.20s:\n", str);
*/
/*
	printf(":%d:\n", x);
	printf(":%5d:\n", x);
	printf(":%+d:\n", x);
	printf(":%+4d:\n", x);
	printf(":%+5d:\n", x);
	printf(":%-5d:\n", x);
	printf(":%05d:\n", x);

	printf(":%.1d:\n", x);
	printf(":%.2d:\n", x);
	printf(":%.3d:\n", x);
	printf(":%.5d:\n", x);
	printf(":%+.5d:\n", x);

	printf("\n");

	ft_printf(":%d:\n", x);
	ft_printf(":%5d:\n", x);
	ft_printf(":%+d:\n", x);
	ft_printf(":%+4d:\n", x);
	ft_printf(":%+5d:\n", x);
	ft_printf(":%-5d:\n", x);
	ft_printf(":%05d:\n", x);

	ft_printf(":%.1d:\n", x);
	ft_printf(":%.2d:\n", x);
	ft_printf(":%.3d:\n", x);
	ft_printf(":%.5d:\n", x);
	ft_printf(":%+.5d:\n", x);
*/
/*
	printf(":%u:\n", x);
	printf(":%5u:\n", x);
	printf(":%-5u:\n", x);
	printf(":%05u:\n", x);

	printf(":%.1u:\n", x);
	printf(":%.2u:\n", x);
	printf(":%.3u:\n", x);
	printf(":%.5u:\n", x);

	printf("\n");
	ft_printf(":%u:\n", x);
	ft_printf(":%5u:\n", x);
	ft_printf(":%-5u:\n", x);
	ft_printf(":%05u:\n", x);

	ft_printf(":%.1u:\n", x);
	ft_printf(":%.2u:\n", x);
	ft_printf(":%.3u:\n", x);
	ft_printf(":%.5u:\n", x);
*/
/*
	printf(":%X:\n", x);
	printf(":%5X:\n", x);
	printf(":%-5X:\n", x);
	printf(":%05X:\n", x);

	printf(":%.1x:\n", x);
	printf(":%.2x:\n", x);
	printf(":%.3x:\n", x);
	printf(":%.5x:\n", x);

	printf("\n");
	ft_printf(":%X:\n", x);
	ft_printf(":%5X:\n", x);
	ft_printf(":%-5X:\n", x);
	ft_printf(":%05X:\n", x);
	ft_printf(":%.1x:\n", x);
	ft_printf(":%.2x:\n", x);
	ft_printf(":%.3x:\n", x);
	ft_printf(":%.5x:\n", x);
*/
/*
	printf(":%o:\n", x);
	printf(":%5o:\n", x);
	printf(":%-5o:\n", x);
	printf(":%05o:\n", x);
	printf(":%.1o:\n", x);
	printf(":%.2o:\n", x);
	printf(":%.3o:\n", x);
	printf(":%.5o:\n", x);

	printf("\n");
	ft_printf(":%o:\n", x);
	ft_printf(":%5o:\n", x);
	ft_printf(":%-5o:\n", x);
	ft_printf(":%05o:\n", x);
	ft_printf(":%.1o:\n", x);
	ft_printf(":%.2o:\n", x);
	ft_printf(":%.3o:\n", x);
	ft_printf(":%.5o:\n", x);
*/
/*
	printf(":%f:\n", y);
	printf(":%15f:\n", y);
	printf(":%+f:\n", y);
	printf(":%+15f:\n", y);
	printf(":%-15f:\n", y);
	printf(":%015f:\n", y);
	printf(":%4f:\n", y);
	printf(":%.f:\n", y);
	printf(":%.0f:\n", y);
	printf(":%4.5f:\n", y);
	printf(":%.7f:\n", y);

	printf(":%.1f:\n", y);
	printf(":%.2f:\n", y);
	printf(":%.3f:\n", y);
	printf(":%.5f:\n", y);
	printf(":%+.5f:\n", y);
	printf(":%.12f:\n", y);

	printf("\n");

	ft_printf(":%f:\n", y);
	ft_printf(":%15f:\n", y);
	ft_printf(":%+f:\n", y);
	ft_printf(":%+15f:\n", y);
	ft_printf(":%-15f:\n", y);
	ft_printf(":%015f:\n", y);
	ft_printf(":%4f:\n", y);
	ft_printf(":%.f:\n", y);
	ft_printf(":%.0f:\n", y);
	ft_printf(":%4.5f:\n", y);
	ft_printf(":%.7f:\n", y);
	ft_printf(":%.1f:\n", y);
	ft_printf(":%.2f:\n", y);
	ft_printf(":%.3f:\n", y);
	ft_printf(":%.5f:\n", y);
	ft_printf(":%+.5f:\n", y);
	ft_printf(":%.12f:\n", y);
*/
/*
	printf(":%a:\n", y);
	printf(":%15a:\n", y);
	printf(":%+a:\n", y);
	printf(":%+15a:\n", y);
	printf(":%-15a:\n", y);
	printf(":%015a:\n", y);
	printf(":%4a:\n", y);
	printf(":%.a:\n", y);
	printf(":%.0a:\n", y);
	printf(":%4.5a:\n", y);
	printf(":%.7a:\n", y);

	printf(":%.1a:\n", y);
	printf(":%.2a:\n", y);
	printf(":%.3a:\n", y);
	printf(":%.5a:\n", y);
	printf(":%+.5a:\n", y);
	printf(":%.12a:\n", y);

	printf("\n");
*/


	//printf("This is a simple test.");
	//printf("\n");
	//ft_printf("This is a simple test.");
	cow = printf("%ld", (long)INT_MAX + 1);
	printf("\n");
	cow2 = ft_printf("%ld", (long)INT_MAX + 1);
	printf("\ncow :%d\ncow2:%d\n", cow, cow2);
	return (0);
}
