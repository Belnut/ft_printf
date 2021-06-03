#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	int count;

	count = ft_printf("hello world!\n");
	printf("%d\n", count);
}
