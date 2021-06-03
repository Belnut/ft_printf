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

	count = printf("%10*0d\n", 10, 'c');
	printf("count = %d\n", count - 1);

	count = printf("%10*00d\n", 10, 'c');
	printf("count = %d\n", count - 1);
	
	printf("check unused format\n");
	count = printf("% \n", 'c');
	printf("count = %d\n", count - 1);

	count = printf("%zzzzzd, %  d\n", 'c', 10);
	printf("count = %d\n", count - 1);

	count = printf("%0010d\n", 10);

}
