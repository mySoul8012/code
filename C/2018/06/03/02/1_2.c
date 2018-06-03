#include <stdio.h>

int input_number(int number[], int i);	// 输入10个整数
int input_tmp();	// 获取一个数
int insert_array(int tmp, int number[], int i); // 实现数组的有序插入	
int put_number(int number[], int i);	// 实现数组的输出

int move_array_by_one(int number[], int sub1, int sub2); // 实现数组移动一位

int main()
{
	int number[6];
	int tmp;
	
	input_number(number, 4);	// 输入5个整数
	
	tmp = input_tmp(); // 输入一个数
	
	insert_array(tmp, number, 4);	// 实现数组的有序插入
	
	put_number(number, 5);	// 实现数组的输出
	
	return 0;
}

// 输入5个整数
// 输入 数组 int
// 输出 数组 int
int input_number(int number[], int i)
{
	int j;
	
	printf("输入5个整数");
	for(j=0; j<=i; j++)
	{
		scanf("%d", &number[j]);
	}
	
	return 1;
}

// 获取一个数
// 输入 数 int
// 输出 数 int
int input_tmp()
{
	int tmp;
	
	scanf("%d", &tmp);
	
	return tmp;
}


// 实现数组的有序插入
// 输入 数组 插入的数 int
// 输出 插入后数组 int
int insert_array(int tmp, int number[], int i)
{
	int j;
	int flag;
	
	for (j=0; j<=i; j++)
	{	
		// 输入的数是数组中数最小的情况
		if (j == 0 && tmp <= number[j])
		{
			move_array_by_one(number, j, i+1);
			flag = j;
		}
		
		// 输入的数是数组中数处于中间的情况
		if (j >= 0 && j < i)
		{
			if (tmp >= number[j] && tmp <= number[j+1])
			{
				move_array_by_one(number, j+1, i+1);
				flag = j+1;
			}
		}
		
		// 输入的数是数组中数最大的情况
		if (j == i && tmp >= number[j])
		{
			flag = j+1;
		}
	}
	number[flag] = tmp;
	return 1;
}

// 实现数组移动一位
// 输入 数组 要移动前的最小序号 移动完成以后的最大的序号 int
// 输出 移动完成后的数组
int move_array_by_one(int number[], int sub1, int sub2)
{
	int i;
	int j;
	i = sub2 - sub1;
	
	for (j=1; j<=i; j++)
	{
		number[sub2] = number[sub2-1];
		sub2 -= 1;
	}
	return 1;
}

// 数组的输出
// 输入 数组 
// 输出数组
int put_number(int number[], int i)
{
	int j;
	for (j=0; j<=i; j++)
	{
		printf("%d\t", number[j]);
	}
	return 1;
}