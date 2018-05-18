#include <stdio.h>

int power(int number, int n);

int main()
{
	int number;
	int n;

	number = 2;
	n = 3;

	number = power(number, n);    // 调用函数 power power函数为计算number的n次方

	printf("这个数的 %d 次方的结果为 %d\n", n, number);

	return 0;
}

// 函数计算一个数的n次方 power 函数
int power(int number, int n)
{
	if(n!=0)
	{
		number = number * power(number, n-1);     
		return number;
	}
	else
	{
		return 1;
	}
}
