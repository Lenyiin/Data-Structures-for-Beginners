#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化
LTNode* ListInit();

//打印链表
void ListPrint(LTNode* phead);

//尾插
void ListPushBack(LTNode* phead, LTDateType x);

//尾删
void ListPopBack(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDateType x);

//头删
void ListPopFront(LTNode* phead);

//扩容
LTNode* BListNode(LTDateType x);

//查找
LTNode* ListFind(LTNode* phead, LTDateType x);

//在指定位置之前的插入
void ListInsert(LTNode* pos, LTDateType x);

//在指定位置的删除
void ListErase(LTNode* pos);

//销毁空间
void ListDestroy(LTNode* phead);