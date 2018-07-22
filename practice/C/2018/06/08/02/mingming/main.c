#include <stdio.h>
#include "header.h"

int main(int argc, char** argv) {
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
