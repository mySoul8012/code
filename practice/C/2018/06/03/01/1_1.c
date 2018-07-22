#include <stdio.h>

int preservation(int number[], int i);	// 获取输入的10个整数
int output(int number[], int i);	// 对于整形数组的输出
int max_sub(int number[], int i, int *p_max);	// 对应的最大项的下标
int min_sub(int number[], int i, int *p_min);	// 对应的最小项的下标
int exchange(int number[], int i, int sub1, int sub2);	// 交换两个元素
int put(int number[], int i);	// 输出数组

int main()
{
	int number[10];
	int maxSub, minSub;
	int sub1, sub2;
	
	printf("请输入10个整数");
	preservation(number, 9);	// 获取输入的10个整数
	fflush(stdin);
	
	output(number, 9);	// 对于整形数组的输出
	
	max_sub(number, 9, &maxSub);	// 对应的最大项的下标
	printf("最大项的下标为%d\n", maxSub);
	
	min_sub(number, 9, &minSub);		// 对应的最小项的下标
	printf("最小项的下标为%d\n", minSub);
	
	printf("请输入要交换的两个元素\n");
	scanf("%d %d", &sub1, &sub2);
	exchange(number, 9, sub1, sub2);	// 交换两个元素
	fflush(stdin);
	
	put(number, 9);	// 输出数组

	return 0;	
}

// 获取输入的10个整数
// 输入 数组 数组最大下标 int
// 输出 数组 int
int preservation(int number[], int i)
{
	int j;
	for (j=0 ; j<=i; j++)
	{
		scanf("%d", &number[j]);
	}
	
	return 0;
}

// 对于整形数组的输出
// 输入 数组 数组最大的下标 int
// 输出 数组 int
int output(int number[], int i)
{
	int j;
	for (j=0; j<=i; j++)
	{
		printf("%d\t", number[j]);
	}
	printf("\n");
	
	return 0;
}

// 对应的最大项的下标
// 输入 数组 数组的最大下标 int
// 输出 数组 最大值对应的下标 int
int max_sub(int number[], int i, int *p_max)
{
	int numberMax;
	int j;
	
	numberMax = number[0];
	*p_max = 0;
	
	for (j=1; j<=i; j++)
	{
		if(number[j] >= numberMax)
		{
			numberMax = number[j];
			*p_max = j;
		}
	}
	
	return 0;
}

// 对应最小项的下标
// 输入 数组 数组的最大的下标 int
// 输出 数组 最小值对应的下标 int
int min_sub(int number[], int i, int *p_min)
{
	int numberMin;
	int j;
	
	numberMin = number[0];
	*p_min = 0;
	
	for (j=1; j<=i; j++)
	{
		if (number[j] <= numberMin)
		{
			numberMin = number[j];
			*p_min = j;
		}
	}
	
	return 0;
}

// 交换两个元素
// 输入 数组 最大的下标 交换的元素的两个下标 int
// 输出 交换后的数组  int
int exchange(int number[], int i, int sub1, int sub2)
{
	int j;
	int tmp;
	
	for (j=0; j<=i; j++)
	{
		if(j == sub1)
		{
			tmp = number[j];
			number[j] = number[sub2];
			number[sub2] = tmp;
		}
	}
	
	return 0;
}

// 输出数组函数
// 输入 数组 最大的下标
// 输出 数组
int put(int number[], int i)
{
	int j;
	
	for (j=0; j<=i; j++)
	{
		printf("%d\t", number[j]);
	}
	printf("\n");
	
	return 0;
}