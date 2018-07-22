#include <stdio.h>

int main()
{
	int a;
	int *p_a;
	int *p_b;

	a = 1;
	p_a = &a;

	printf("%d\n", a);
	printf("%p\n", &a);

	printf("%d\n", *p_a);
	printf("%p\n", p_a);
	printf("%p\n", &(*p_a));

	p_b = &(*p_a);
	printf("%d\n", *p_b);
	printf("%p\n", p_b);
	printf("%p\n", p_a);

	a = 2;
	printf("%d\n", *p_b);
	printf("%p\n", p_b);
	printf("%p\n", p_a);

	return 0;
}