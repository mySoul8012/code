#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10
void bassicYangHui(void);
void bassicYangHui2(void);
int eval(int row, int col);
void bassicYangHui3(void);

int main()
{
	bassicYangHui();
	bassicYangHui2();
	bassicYangHui3();
	return 0;
}

// 计算并输出杨辉三角
void bassicYangHui(void)
{
	int yanHui[MAX_ROW][MAX_COL] = {{0}};
	int i, j;

	for(i=0; i<MAX_ROW; i++)
	{
		for(j=0; j<=i; j++)
		{
			if (j==0 || j==i)
			{
				yanHui[i][j] = 1;
			}
			else
			{
				yanHui[i][j] = yanHui[i-1][j-1] + yanHui[i-1][j];
			}
		}
	}

	// 输出杨辉三角
	for(i=0; i<MAX_ROW; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("%5d", yanHui[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 对称性折半 二分查找
void bassicYangHui2(void)
{
	int yanHui[MAX_ROW][MAX_COL] = {{0}};
	int i, j;

	for(i=0; i<MAX_ROW; i++)
	{
		yanHui[i][0] = yanHui[i][i] = 1;	// 完成左右两边赋值为 1
	}

	for(i=0; i<MAX_ROW; i++)
	{
		for(j=1; j<(i/2+1); j++)
		{
			yanHui[i][j] = yanHui[i-1][j-1] + yanHui[i-1][j];
		}

		for(j=i; j>(i/2); j--)
		{
			yanHui[i][j] = yanHui[i][i-j];
		}
	}

	// 输出杨辉三角
	for(i=0; i<MAX_ROW; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("%5d", yanHui[i][j]);
		}
		printf("\n");
	}

}

// 利用递归输出杨辉三角
// 求第i行第j列的值
int eval(int row, int col)
{
	if(col == 0 || col == row)
	{
		return 1;
	}
	else
	{
		return eval(row-1, col-1) + eval(row-1, col);
	}
}

// 输出杨辉三角
void bassicYangHui3(void)
{
	int i;
	int j;

	for(i=0; i<MAX_ROW; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("%5d", eval(i, j));
		}
		printf("\n");
	}
}


