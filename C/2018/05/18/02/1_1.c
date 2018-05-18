#include <stdio.h>

int f(int n);

int main()
{
	int n;
	int n_number;

	printf("请输入一个数\n");
	scanf("%d", &n);

	n_number = f(n);

	printf("%d\n", n_number);

	return 0;
}

int f(int n)
{
	if(n <= 2)
	{
		return 1;
	}
	else
	{
		return f(n - 1) + f(n + 1);
	}
}