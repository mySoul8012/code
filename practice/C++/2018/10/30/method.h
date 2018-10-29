#pragma once
#include "store.h"
// method.h 单链表
// 0 号节点为头节点 1号节点开始存储内容
class list {
public: 
	list();	// 构造函数
	~list();	// 析构函数
	int getLength();	// 获得链表长度
	list* getList(); // 获得链表
	string toString();	// 获得result字符串
	list* deleteString();	// 清空result字符串，并返回指向该类的指针
	list* setString(string& msg);	// 设置result字符串
	string toError();	// 获得error
	list* insertElem_Head(Node& node);	// 头插法，插入元素
	list* insertElem_Foot(Node& node);	// 尾插法，插入元素
	Node* getNumNode(const string& num);	// 根据键值查找指定节点,返回指向该节点的指针
	Node* getNode(const int& loc);	// 获取指定loc的节点，返回指向该节点的指针
	Node* insertLoc(Node& node, int& loc);	// 插入指定位置的元素
	list* deleteNode(const int& loc);	// 删除节点
	list* reverse();	// 反转链表
	list* TwoPoints();	// 链表一分为二，返回第二个链表的头
private:
	Node* head;	// 链表头结点
	int length=NULL;	// 链表的长度
	string result = "";	// 临时保存结果
	string error;	// 保存错误
	bool judgingRingList();	// 判断环单链表
	int createList();	// 创建链表
	int destroyList();	// 释放线性表
};