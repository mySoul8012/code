#include <stdio.h>

int main()
{
	int number;
	int count;
	int ten;

	ten=10;
	count=0; 

	// 获取输入的数，并赋值于 number
	printf("请输入一个数\n");
	scanf("%d", &number);

	// 判断位数
	while(((int)(number/ten))!=0)
	{
		count++;
		ten*=10;
	}

	// 少记一位，重新加上
	count++;

	printf("%d 的位数为 %d\n", number, count);

	return 0;
}