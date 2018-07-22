#include <stdio.h>
#include "typedef.h"

// 函数定义
int read(spot *p_coordinate, circle *p_cir);	// 获取圆和点
int point_garden(spot coordinate, circle cir);	// 判断一个点是否在一个园内
double computational_distance(spot coordinate, circle cir);	// 计算圆和点之间的距离
double distance(circle cir1, circle cir2);	// 计算两个圆距离函数

