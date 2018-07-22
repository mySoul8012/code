#include <stdio.h>

int main()
{
	int number;
	int n;

	printf("Please enter a number\n");
	scanf("%d", &number);

	printf("Please enter a power\n");
	scanf("%d", &n);

	// 进行累加 每次累加一次n的值减少一次，直到n变为0，条件为假，循环结束。
	// 由于累加次数和循环次数每次相差1，故循环条件减1
	while(n-1)
	{
		number+=number;
		n--;
	}

	printf("power = %d", number);

	return 0;

}