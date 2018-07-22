#include <stdio.h>
#include <math.h>

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

// 函数定义
int read(spot *p_coordinate, circle *p_cir);	// 获取圆和点
int point_garden(spot coordinate, circle cir);	// 判断一个点是否在一个园内
double computational_distance(spot coordinate, circle cir);	// 计算圆和点之间的距离
double distance(circle cir1, circle cir2);	// 计算两个圆距离函数
double two_point_distance(spot coordinate1, spot cordinate2);	// 两点间距离计算

int main() {
	spot coordinate;	// 坐标
	circle cir1,cir2;	// 圆
	int result;	// 保存结果

	// 判断一个点是否在一个圆内
	printf("开始判断点是否在园内\n");
	read(&coordinate, &cir1);	// 获取圆的坐标和点的坐标
	result = point_garden(coordinate, cir1);	// 进行判断
	// 输出判断结果
	if(result == 1)
		printf("点在圆外\n");
	else if(result == 0)
		printf("点在圆上\n");
	else if(result == -1)
		printf("点在圆内\n");
	else
		printf("点和圆心重合\n");

	// 计算一个点与一个圆之间的距离
	printf("开始计算点和圆的距离\n");
	read(&coordinate, &cir1);	// 获取圆的坐标和点的坐标
	printf("点和圆的距离为 %lf\n", computational_distance(coordinate, cir1));	// 计算点和圆的距离并输出结果

	// 计算两个圆之间的距离
	printf("开始计算两个圆的距离\n");
	read(&coordinate, &cir1);	// 获取第一个圆
	read(&coordinate, &cir2);	// 获取第二个圆
	printf("两个圆之间的距离为 %lf\n", distance(cir1, cir2));	// 计算两个圆的距离并输出结果

	return 0;
}

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

// 计算两点的距离
double two_point_distance(spot coordinate1, spot cordinate2)
{
	double x, y;
	x = coordinate1.x - cordinate2.x;
	y = coordinate1.y - cordinate2.y;
	return sqrt(pow(x,2) + pow(y,2));
}