#include <stdio.h>

int		main()
{
	int count;

	count = printf("%10.03f\n", 100.02);
	printf("count = %d\n", count - 1);

	count = printf("%zzzzzd, %  d\n", 'c', 10);
	printf("count = %d\n", count - 1);

	count = printf("%0010d\n", 10);

}
