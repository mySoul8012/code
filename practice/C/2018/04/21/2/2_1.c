#include <stdio.h>

int main()
{
	int number;
	int i=0;

	printf("number\n");
	scanf("%d", &number);

	while(number!=0)
	{
		number = ((int)((double)number / 10));
		i++;
	}

	printf("%d", i);

	getchar();
	getchar();

	return 0;
}