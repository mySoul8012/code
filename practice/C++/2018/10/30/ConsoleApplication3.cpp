// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "method.h"
#include "store.h"
#include "typeRedefinition.h"
#include <iostream>

int main() {
	// 储存当前创建的链表表 指针数组
	list* listNode[200]; int i = 0;	// 链表
	Node* NodeList[200]; int n = 0;	// 节点
	int NodeTmp = 0;	// 选择的节点
	int ListTmp = 0;	// 选择的list

	// 获取选项
	int option;
	bool whileTmp = true;
	while (whileTmp) {
		// 菜单
		cout << "请输入选项" << endl;
		cout << "-------------------------------" << endl;
		cout << "节点相关" << endl;
		cout << "1 创建一个节点" << endl;
		cout << "2 填入节点的相关信息" << endl;
		cout << "4 获取临时储存的节点" << endl;
		cout << "单链表相关" << endl;
		cout << "5 创建一个单链表" << endl;
		cout << "6 获取当前创建的单链表个数" << endl;
		cout << "7 获取链表长度" << endl;
		cout << "8 输出链表的全部内容" << endl;
		cout << "9 头插法 插入链表,并输出全部链表" << endl;
		cout << "10 尾插法 插入链表，并输出全部链表" << endl;
		cout << "11 根据键值查找指定节点 并输出节点的内容" << endl;
		cout << "12 根据输入的loc获取指定的节点内容 " << endl;
		cout << "13 将临时储存的节点进行插入的单链表中" << endl;
		cout << "14 删除节点，并输出节点" << endl;
		cout << "15 将链表反转，输出节点" << endl;
		cout << "16 将链表一分为二，输出第二个链表的内容" << endl;
		cout << "18 删除节点 " << endl;
		cout << "19 删除链表 " << endl;
		cout << "17 退出" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "进行创建节点操作" << endl;
			NodeList[n] = new Node();
			n++;
			cout << "创建节点成功" << endl;
			cout << "--------------------------------------" << endl;
		}
		break;
		case 2:
		{
			string tmp = "";
			int intTmp = 0;
			cout << "填入节点的相关信息" << endl;
			cout << "将会输出目前的暂时保持的节点为,统统重0开始   " << n << endl;
			cout << "请输入选择填入的节点   " << endl; cin >> NodeTmp;
			if (NodeTmp > n) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "进行节点内容的填写" << endl;
			cout << "请输入学号" << endl; cin >> tmp;
			NodeList[NodeTmp]->setNum(tmp);
			cout << "请输入姓名" << endl; cin >> tmp;
			NodeList[NodeTmp]->setName(tmp);
			cout << "请输入年龄" << endl; cin >> intTmp;
			NodeList[NodeTmp]->setAge(intTmp);
			cout << "请输入专业" << endl; cin >> tmp;
			NodeList[NodeTmp]->setMajor(tmp);
			cout << "请输入入学年份" << endl; cin >> intTmp;
			NodeList[NodeTmp]->setRegissterYear(intTmp);
			cout << "输入完成" << endl;
		}
		break;
		case 4:
		{
			cout << "4 获取临时储存的节点" << endl;
			cout << "将会输出目前的暂时保持的节点为,统统重0开始" << n << endl;
			cout << "请输入选择填入的节点" << endl; cin >> NodeTmp;
			if (NodeTmp > n-1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "节点内容的输出" << endl;
			cout << "学号 " << NodeList[NodeTmp]->getNum() << endl;
			cout << "姓名 " << NodeList[NodeTmp]->getName() << endl;
			cout << "年龄 " << NodeList[NodeTmp]->getAge() << endl;
			cout << "专业 " << NodeList[NodeTmp]->getMajor() << endl;
			cout << "入学年份 " << NodeList[NodeTmp]->getRegissterYear() << endl;
		}
		break;
		case 5:
		{
			cout << "创建一个单链表" << endl;
			listNode[i] = new list();
			i++;
			cout << "创建单链表成功" << endl;
		}
		break;
		case 6:
		{
			cout << "获取当前创建的单链表个数  ";
			cout << i << endl;
		}
		break;
		case 7:
		{
			cout << "获取链表长度" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i-1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "链表长度为 " << listNode[ListTmp]->getLength() << endl;
		}
		break;
		case 8:
		{
			cout << "输出链表的全部内容" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "输出内容" << endl;
			cout << listNode[ListTmp]->deleteString()->getList()->toString() << endl;
			cout << "输出结束" << endl;
		}
		break;
		case 9:
		{
			cout << "头插法 插入链表, 并输出全部链表" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i-1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "将会输出目前的暂时保持的节点为,统统重0开始" << n << endl;
			cout << "请输入选择填入的节点" << endl; cin >> NodeTmp;
			if (NodeTmp > n-1) {
				cout << "输入有误" << endl;
				break;
			}
			listNode[ListTmp]->insertElem_Head(*NodeList[NodeTmp]);
			cout << "创建完成" << endl;
		}
		break;
		case 10:
		{
			cout << "尾插法 插入链表，并输出全部链表" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "将会输出目前的暂时保持的节点为,统统重0开始" << n << endl;
			cout << "请输入选择填入的节点" << endl; cin >> NodeTmp;
			if (NodeTmp > n - 1) {
				cout << "输入有误" << endl;
				break;
			}
			listNode[ListTmp]->insertElem_Foot(*NodeList[NodeTmp]);
			cout << "创建完成" << endl;
		}
		break;
		case 11:
		{
			string tmp;
			cout << "根据键值查找指定节点 并输出节点的内容" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "请输入要查询的键值"; cin >> tmp;
			cout << "结果" << endl;
			cout << "年龄 " << listNode[ListTmp]->getNumNode(tmp)->getAge() << endl;
			cout << "专业 " << listNode[ListTmp]->getNumNode(tmp)->getMajor() << endl;
			cout << "姓名 " << listNode[ListTmp]->getNumNode(tmp)->getName() << endl;
			cout << "学号 " << listNode[ListTmp]->getNumNode(tmp)->getNum() << endl;
			cout << "入学年份 " << listNode[ListTmp]->getNumNode(tmp)->getRegissterYear() << endl;
		}
		break;
		case 12: {
			int tmp;
			cout << "根据输入的loc获取指定的节点内容" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "请输入要查询的loc"; cin >> tmp;
			cout << "结果" << endl;
			cout << "年龄 " << listNode[ListTmp]->getNode(tmp)->getAge() << endl;
			cout << "专业 " << listNode[ListTmp]->getNode(tmp)->getMajor() << endl;
			cout << "姓名 " << listNode[ListTmp]->getNode(tmp)->getName() << endl;
			cout << "学号 " << listNode[ListTmp]->getNode(tmp)->getNum() << endl;
			cout << "入学年份 " << listNode[ListTmp]->getNode(tmp)->getRegissterYear() << endl;
		}
				 break;
		case 13:
		{
			int tmp, tmp1;
			cout << "将临时储存的节点进行插入的单链表中" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "当前创建的节点个数为 从0开始计数 " << n << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "请输入要插入的node"; cin >> tmp;
			if (NodeTmp > n - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "请输入要插入到list中的位置"; cin >> tmp1;
			listNode[ListTmp]->insertLoc(*NodeList[tmp], tmp);
			cout << "输出内容" << endl;
			cout << listNode[ListTmp]->deleteString()->getList()->toString() << endl;
			cout << "输出完成" << endl;
		}
		break;
		case 14:
		{
			int tmp;
			cout << "删除节点" << endl;
			cout << "将临时储存的节点进行插入的单链表中" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "当前创建的节点个数为 从0开始计数 " << n << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << "请输入要删除的node"; cin >> tmp;
			cout << listNode[ListTmp]->deleteNode(tmp)->deleteString()->getList()->toString() << endl;
		}
		break;
		case 15:
		{
			int tmp;
			cout << "将链表反转，输出节点" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "当前创建的节点个数为 从0开始计数 " << n << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << listNode[ListTmp]->reverse()->deleteString()->getList()->toString() << endl;
		}
		break;
		case 16:
		{
			int tmp;
			cout << "将链表一分为二，输出第二个链表的内容" << endl;
			cout << "当前创建的链表个数为 从0 开始计数 " << i << endl;
			cout << "当前创建的节点个数为 从0开始计数 " << n << endl;
			cout << "选择链表 "; cin >> ListTmp;
			if (ListTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			cout << listNode[ListTmp]->TwoPoints()->deleteString()->getList()->toString() << endl;
		}
		case 17:
		{
			cout << "选择程序退出" << endl;
			whileTmp = false;
		}
			break;
		case 18:
		{
			int nTmp;
			cout << "删除节点" << endl;
			cout << "当前创建的节点个数为 从0开始计数 " << n << endl;
			cout << "输入要删除的节点 "; cin >> nTmp;
			if (nTmp > n - 1) {
				cout << "输入有误" << endl;
				break;
			}
			delete NodeList[nTmp];
			NodeList[nTmp] = NULL;
		}
		case 19:
		{
			int nTmp;
			cout << "删除链表" << endl;
			cout << "当前创建的链表个数为 从0开始计数 " << i << endl;
			cout << "输入要删除的节点 "; cin >> nTmp;
			if (nTmp > i - 1) {
				cout << "输入有误" << endl;
				break;
			}
			delete listNode[nTmp];
			listNode[nTmp] = NULL;
		}
		default:
			cout << "输入有误 请重新输入" << endl;
			break;
		}
	}
	return 0;
}
