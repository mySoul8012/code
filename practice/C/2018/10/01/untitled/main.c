#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCOUNT 50
// 定义要储存的线性表
typedef struct {
    char num[20];   // 定义学号
    char name[20];  // 定义姓名
    int age;    // 定义年龄
    char major[20]; // 定义专业
    int registerYear;   // 定义入学年份
}ElemType;

// 定义线性表的物理储存
typedef struct {
    ElemType data[MAXCOUNT];    // 定义数据
    int len;    // 定义长度
}SeqList;

int createList(SeqList **myList);
int listLength(const SeqList *myList);
int printfList(const SeqList *myList);
int inputList(ElemType **tmpList, int *col);
int moveList(SeqList *myList, int col, int option);
int selectList(SeqList *myList, char *key);
int infoList(SeqList *myList, int key);
int DestroyList(SeqList *myList);

int main() {
    // 定义一些变量
    int option, tmp;
    SeqList *myList; // 定义一个SeqList类型的空指针，用来储存线性表
    myList = NULL;
    char key[20];
    int num;

    // 输出选项
    printf("学生管理系统进入成功\n");
    printf("************选项*******************\n");
    printf("1 建立线性表\n");
    printf("2 求线性表的长度\n");
    printf("3 输出详细表\n");
    printf("4 在线性表的位置插入一个元素\n");
    printf("5 根据键值对查找指定的元素\n");
    printf("6 获取指定位置的元素的信息\n");
    printf("7 删除指定位置的元素\n");
    printf("8 释放线性表\n");
    printf("9 退出系统\n");
    printf("**************end!*********************\n");

    // 进行选项的输入
    // 进行基本逻辑的处理
    while(1) {
        printf("请输入选项\n");
        scanf("%d", &option);
        switch(option) {
            // 建立线性表
            case 1:
                tmp = createList(&myList);   // 捕获结果，并创建线性表
                // 输出结果
                if (tmp == 1) {
                    printf("建立线性表成功！\n");
                } else {
                    printf("建立线性表失败!\n");
                };
                break;
            // 查询线性表的长度
            case 2:
                tmp = listLength(myList);
                if (tmp == -1) {
                    printf("查询线性表长度失败，未指定线性表\n");
                } else {
                    printf("查询线性表的长度为%d\n", tmp);
                };
                break;
            // 输出线性表
            case 3:
                tmp = printfList(myList);
                if (tmp == -1)
                    printf("输出线性表失败，未指定线性表\n");
                else
                    printf("输出线性表如上\n");
                break;
             // 插入线性表
             case 4:
                tmp = insterList(myList);
                if (tmp == -1)
                    printf("插入线性表失败\n");
                else
                    printf("插入线性表成功\n");
                break;
            case 5:
                // 根据键值查找索引值
                printf("请输入键值,即学号\n");
                fflush(stdin);
                gets(key);
                fflush(stdin);
                tmp = selectList(myList, key);
                if (tmp == -1)
                    printf("查找错误\n");
                else if (tmp >= listLength(myList))
                    printf("未找到！");
                else
                    printf("索引值为 %d\n", tmp);
                break;
            case 6:
                // 根据索引值查找键值
                printf("请输入索引值\n");
                scanf("%d", &num);
                tmp = infoList(myList, num);
                if (tmp == -1) {
                    printf("查找失败\n");
                } else {
                    printf("输出的信息如上\n");
                }
                break;
            case 7:
                // 根据键值删除对应的数据
                tmp = deleteList(myList);
                if (tmp == -1)
                    printf("删除失败\n");
                else
                    printf("删除成功");
                break;
            case 8:
                tmp = DestroyList(myList);
                if (tmp == -1) {
                    printf("释放失败\n");
                } else {
                    printf("释放成功\n");
                }
                break;
            case 9:
                return 0;
            default:
                printf("您输入的有错误，请重新输入");
                break;
        }
    }
    return 0;
}

/*
 * 建立线性表
*/
// in 传入空指针 out 线性表的首地址
int createList(SeqList **myList) {
     *myList = (SeqList *)malloc(sizeof(SeqList));    // 申请一块储存空间
    if (*myList == NULL) {
        return -1;   // 创建储存空间失败
    } else {
        return 1;   // 创建储存空间成功
    }
}

/*
 * 求线性表长度,
*/
// in 线性表 out 长度
int listLength(const SeqList *myList) {
    // 未创建线性表
    if (myList == NULL)
        return -1;
    // 创建线性表
    return myList -> len;
};

/*
 * 输出线性表
*/
// in 线性表 out 线性表的内容
int printfList(const SeqList *myList) {
    int i, len;
    // 判断是否为空指针
    if (myList == NULL)
        return -1;
    // 获取线性表长度
    len = myList -> len;
    if (len == 0) {
        printf ("您输入的线性表为空\n");
        return 1;
    }
    // 输出线性表
    for (i = 0; i < len; i++) {
        printf("输出第%d组数组\n", i + 1);
        printf("学号 = %s\n", myList->data[i].num);
        printf("年龄 = %d\n", myList ->data[i].age);
        printf("专业 = %s\n", myList ->data[i].major);
        printf("姓名 = %s\n", myList ->data[i].name);
        printf("入学年份 = %d\n", myList ->data[i].registerYear);
    }
    printf("线性表输出成功\n");
    return 1;
}


/*
 * 在线性表的指定位置插入
*/
// in 线性表 out 结果
int insterList(SeqList *myList) {
    int tmp, col;
    ElemType *tmpList = NULL;
    // 判断传入地址是否为空
    if (myList == NULL) {
        return -1;
    }
    /*
     * 进行插入
     */
    // 获取用户输入
    tmp = inputList(&tmpList, &col);
    // 判断是否获取成功
    if (tmp == -1)
        return -1;
    // 进行插入操作
    // 调用函数，往后逐步移动
    tmp = moveList(myList, col, 1);    // 1代表向后移动  0 向前移动
    // 判断获取结果
    if (tmp == -1) {
        return -1;
    }
    // 将值插入
    myList->data[col-1] = *tmpList;
    // 维护长度
    (myList ->len)++;
    // 释放储存空间
    free(tmpList);
    // 设置空指针
    tmpList = NULL;
    return 1;
}
// 获取用户输入要插入线性表的信息
// in 插入的信息 插入的位置 out 结果
int inputList(ElemType **tmpList, int *col) {
    // 申请储存的内存空间
    *tmpList = (ElemType *)malloc(sizeof(ElemType));
    if (*tmpList == NULL){
        printf("空间不足，无法申请\n");
        return -1;
    }
    // 获取用户的要插入的内容
    fflush(stdin);
    printf("请输入学号\n");
    gets(((*tmpList) ->num));
    fflush(stdin);
    printf("请输入姓名\n");
    gets((*tmpList) ->name);
    fflush(stdin);
    printf("请输入年龄\n");
    scanf("%d",&((*tmpList) ->age));
    fflush(stdin);
    printf("请输入主修专业\n");
    gets((*tmpList)->major);
    fflush(stdin);
    printf("请输入入学年份\n");
    scanf("%d", &((*tmpList)->registerYear));
    fflush(stdin);
    printf("请输入要插入的位置\n");
    scanf("%d", col);
    fflush(stdin);
    return 1;   // 获取用户输入的信息完成
}

// 移动线性表函数
// 其中option中1往后移动，0往前移动 col 为要插入的位置，从1开始
int moveList(SeqList *myList, int col, int option) {
    int i;
    // 判断传入的线性表是否为空
    if (myList == NULL) {
        printf ("线性表为空\n");
        return -1;
    }
    // 判断线性表是否已满
    if (listLength(myList) >= MAXCOUNT) {
        printf("线性表已满，无法插入，请删除后插入\n");
        return -1;
    }
    // 判断col是否越界，导致线性表不连贯
    if ((col > listLength(myList) && col - listLength(myList) != 1 ) || col < 1) {
        printf("输入的插入位置错误，请确认后重新插入\n");
        return -1;
    }
   // 判断前移还是后移
   switch(option) {
        case 1:
            // 线性表往后移动
           // 移动线性表
           col--;
           for(i = listLength(myList); i >= col; i--) {
               myList ->data[i] = myList ->data[i-1];
           };
           break;
        case 0:
            // 线性表往前移动
            col--;
            for(i = col; i < listLength(myList); i++) {
                myList ->data[i] = myList ->data[i+1];
            }
            break;
       default:
           printf("输入的选型错误\n");
           return -1;
    }
    return 1;
}

// 根据键值查找线性表
int selectList(SeqList *myList, char * key) {
    if (myList == NULL) {
        return -1;
    }
    int i;
    // 进行遍历操作
    for (i = 0; i< listLength(myList); i++) {
        if (strcmp(myList ->data[i].num, key) == 0) {
            break;
        }
    }
    return i;
}

// 获取指定位置的元素信息
int infoList(SeqList *myList, int key) {
    if (myList == NULL) {
        return -1;
    }
    // 检查输入的key
    if (key > listLength(myList) || key < 0) {
        return -1;  // 输入的索引错误
    }

    // 输出值对应的学号
    printf("学号 = %s\n", myList ->data[key].num);
    return 1;
}

// 删除元素
int deleteList(SeqList *myList) {
    char num[20];
    int tmp;
    // 检查myList是否为空
    if (myList == NULL) {
        return -1;
    }
    // 获取要删除的学号
    printf("请输入要删除的学号\n");
    fflush(stdin);
    gets(num);
    // 查找对应的索引值
    tmp = selectList(myList, num);
    if (tmp == -1) {
        return -1;
    }
    // 向前移动
    tmp = moveList(myList, tmp, 1);
    if (tmp == -1) {
        return -1;
    }
    return 1;
}

// 释放线性表
int DestroyList(SeqList *myList) {
    if (myList == NULL) {
        return -1;
    }
    free(myList);
    return 1;
}