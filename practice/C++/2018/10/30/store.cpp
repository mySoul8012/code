// store.cpp
#include "pch.h"
#include "store.h"

/*构造函数*/
Node::Node(){
	this->next = NULL;
	Elemtype::setAge(0);
	Elemtype::setMajor("NULL");
	Elemtype::setName("NULL");
	Elemtype::setNum("NULL");
	Elemtype::setRegissterYear(0);
}

/*学号*/
int Elemtype::setNum(string num)
{
	this->num = num;
	return 0;
}

string Elemtype::getNum(){
	return this->num;
}

/*姓名*/
int Elemtype::setName(string name)
{
	this->name = name;
	return 0;
}

string Elemtype::getName()
{
	return this->name;
}

/*年龄*/
int Elemtype::setAge(int age)
{
	this->age = age;
	return 0;
}

int Elemtype::getAge()
{
	return this->age;
}

/*专业*/
int Elemtype::setMajor(string major)
{
	this->major = major;
	return 0;
}

string Elemtype::getMajor()
{
	return this->major;
}

/*入学年份*/
int Elemtype::setRegissterYear(int regissterYear)
{
	this->regissterYear = regissterYear;
	return 0;
}

int Elemtype::getRegissterYear()
{
	return this->regissterYear;
}


