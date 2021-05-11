#include <stdio.h>
#include <string.h>

int	main()
{
	int	count;
	count = printf("%d%d\n", 1, 2);
	printf("-> %d\n", count);
	count = printf("%d%d%d\n", 1, 2, 3, 4, 5);
	printf("-> %d\n", count);
	count = printf("%d%d\n", 1, 3.4);
	printf("-> %d\n", count);
	count = printf("%f%f\n", 1, 2);
	printf("-> %d\n", count);
	count = printf("%s\n", 1);
	printf("-> %d\n", count);
}
