#include <stdio.h>
#include <math.h>
#include "zong.h"

// 获取坐标和圆
// 输入 点的坐标 圆的圆心半径 double
// 返回 成功执行结构0 int
int read(spot *p_coordinate, circle *p_cir)
{
	printf("下面输入点\n");
	printf("请输入点的横坐标\n");
	scanf("%lf", &p_coordinate->x);
	printf("请输入点的纵坐标\n");
	scanf("%lf", &p_coordinate->y);

	printf("下面开始输入了圆\n");
	printf("下面输入圆心\n");
	printf("输入圆心的横坐标\n");
	scanf("%lf", &p_cir->center.x);
	printf("输入圆心的纵坐标\n");
	scanf("%lf", &p_cir->center.y);
	printf("下面输入半径\n");
	scanf("%lf", &p_cir->r);

	return 0;
}

// 判断一个点是否在一个圆内
// 输入一个点 一个圆 double
// 返回 判断的结果
int point_garden(spot coordinate, circle cir)
{
	double result;

	result = two_point_distance(coordinate, cir.center);

	if(result > cir.r)
		return 1;	// 点在圆外
	else if(result == cir.r)
		return 0;	// 点在圆上
	else if(result == 0.0)
		return -2;	// 点在圆心
	else
		return -1;	// 点在圆内

}

// 计算点和圆的距离
// 输入 点 圆
// 输出 判断结果
double computational_distance(spot coordinate, circle cir)
{
	double result;

	result = point_garden(coordinate, cir);	// 判断点和圆的关系
	if(result == 1)	// 点在圆外
	{
		return two_point_distance(coordinate, cir.center);
	}
	else if(result == 0)	// 点在圆上
	{
		return cir.r;
	}
	else if(result == -2)	// 点和圆心重合
	{
		return cir.r;
	}
	else	// 点在圆内
	{
		return cir.r - two_point_distance(coordinate, cir.center);
	}
}

// 计算两个圆之间的距离
// 输入两个圆
// 输出两个圆的距离
double distance(circle cir1, circle cir2)
{
	double dis;
	dis = two_point_distance(cir1.center, cir2.center);

	if(dis > (cir1.r + cir2.r))	// 两圆相离
	{
		return dis - cir1.r - cir2.r;
	}
	else if(dis == (cir1.r + cir2.r))	// 两圆内切，外切
	{
		return 0;
	}
	else 	// 两圆内含
	{
		return fabs(cir1.r - cir2.r);
	}
}


