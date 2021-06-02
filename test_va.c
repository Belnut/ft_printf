#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void		func1(va_list *ap)
{
	int data;

	data = va_arg(*ap, int);
	printf("func1 : %d\n", data);
}

void		func2(va_list *ap)
{
	int data;

	data = va_arg(*ap, int);
	printf("func2 : %d\n", data);
}

void	func(int size, ...)
{
	va_list ap;
	int a;

	a = 0;
	va_start(ap, size);
	while (a < size)
	{
		if (a % 2 == 0)
			func1(&ap);
		else
			func2(&ap);
		a++;
	}
	va_end(ap);
}
		
int main()
{
	func(5,1,2,3,4,5);
}
