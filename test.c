#include <stdio.h>
#include <string.h>
#include <limits.h>

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
	printf("%06.5d, %5.d\n", 123, 123);
	printf("%06u, %x %X\n", 100, 100, 100);
	printf("%06d", -100);
	count = printf("%z", 100);
	printf("\n count : %d\n", count);
	
	printf("%0d\n", 5);
	printf("%d\n", INT_MIN / -10);
	printf("%d\n", -0x10);
	if (0x10 == 16)
		printf("%020s\n","hello world!\n");
	printf("%020llld\n", LONG_MAX);
	printf("%+d\n", 0);
}
