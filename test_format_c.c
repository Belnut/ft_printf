#include <stdio.h>

int		main()
{
	int count;

	count = printf("%c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%+c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%10+c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%-10c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%10-c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%10c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%010c\n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%*c\n", 10, 'c');
	printf("count = %d\n", count - 1);

	count = printf("%*5c\n", 10, 'c');
	printf("count = %d\n", count - 1);

	count = printf("%5*c\n", 10, 'c');
	printf("count = %d\n", count - 1);

}
