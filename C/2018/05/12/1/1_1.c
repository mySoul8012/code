#include <stdio.h>
#include <math.h>

int main()
{
	int number, originalNumber;
	int result, residue;
	int i;

	printf("请输入一个多位整数\n");
	scanf("%d", &number);

	originalNumber = number;
	result = 0;
	residue = 0;
	i = 0;

	// 判断有多少位
	while(number != 0)
	{
		number /= 10;
		i++;
	}

	// 恢复number数，送入下面的程序
	number = originalNumber;

	// 输出该数的阿姆斯特数计算完成后的结果
	while(number != 0)
	{
		residue = number % 10;
		result += pow(residue, i);
		number /= 10;
	}

	// 进行数的判断
	if(result == originalNumber)
	{
		printf("您输入的 %d 是阿姆斯壮数\n", originalNumber);
	}
	else
	{
		printf("您输入的 %d 不是阿姆斯壮数\n", originalNumber);
	}

	return 0;
}