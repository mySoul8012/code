#include <stdio.h>

int main(void)
{
	int number, flag;
	int i;

	flag = 1;

	printf("请输入一个数\n");
	scanf("%d", &number);

	for(i=2; i<(number/2); i++)
	{
		if(number % i == 0)
		{
			flag = 0;
			break;	// 只需要举出一个反例
		}
	}

	if(flag == 1)
	{
		printf("您输入的是素数\n");
	}
	else
	{
		printf("您输入的不是素数\n");
	}

	return 0;
}