#include <stdio.h>

// 结构定义
// 定义一个点
typedef struct 
{
	double x;
	double y;
}spot;
// 定义一个圆
typedef struct 
{
	spot center;	// 圆心
	double r;	// 半径
}circle;

