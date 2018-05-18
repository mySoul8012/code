#include <stdio.h>

//字符串反转函数
int palindrome_number(int number);

int main()
{
	int number;

	printf("请输入一个数\n");
	scanf("%d", &number);

	if(palindrome_number(number) == number)
	{
		printf("您输入的是回文数\n");
	}
	else
	{
		printf("您输入的不是回文数\n");
	}

	return 0;
}

int palindrome_number(int number)
{
	int number_2;

	number_2 = 0;

	while(number != 0)
	{
		number_2 = number_2*10 + number%10;
		number /= 10;
	}

	return number_2;
}