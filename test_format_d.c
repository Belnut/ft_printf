#include <stdio.h>

int		main()
{
	int count;

	count = printf("%5.03d\n", 100);
	printf("count = %d\n", count - 1);

	count = printf("%zzzzzd, %  d\n", 'c', 10);
	printf("count = %d\n", count - 1);

	count = printf("%10d\n", -100);
	printf("count = %d\n", count - 1);

	count = printf("%010d\n", -100);
	printf("count = %d\n", count - 1);

	count = printf("%+010d\n", 100);
	printf("count = %d\n", count - 1);
}
