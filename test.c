#include <stdio.h>
#include <string.h>

int	main()
{
	int	count;
	char c = 'a';

	count = printf("%d%d\n", 1, 2);
	printf("-> %d\n", count);
	count = printf("%d%d%d\n", 1, 2, 3, 4, 5);
	printf("-> %d\n", count);
	count = printf("%d%d\n", 1, 3.4);
	printf("-> %d\n", count);
	count = printf("%f%f\n", 1, 2);
	printf("-> %d\n", count);

	printf("%c : %-c : %0c : %.c : %*c\n", c, c, c, c, 5, c); 
	printf("%06.5d, %5.d", 123, 123);
}
