#pragma once
// store.h 储存的结构体
#include "typeRedefinition.h"
#define Node_Length 20

/*储存基本的储存结构*/
class Elemtype {
private:
	string num;	// 学号
	string name;	// 姓名
	int age;	// 年龄
	string major;	// 专业
	int regissterYear;	// 入学年份
public:
	int setNum(string num);
	string getNum();
	int setName(string name);
	string getName();
	int setAge(int age);
	int getAge();
	int setMajor(string major);
	string getMajor();
	int setRegissterYear(int regissterYear);
	int getRegissterYear();
};

/*节点*/
class Node: public Elemtype{
public:
	Node* next = NULL;
	Node();
};