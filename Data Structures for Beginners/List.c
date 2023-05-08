#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"


//初始化
LTNode* ListInit()
{
	//建立哨兵位节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//打印链表
void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//尾插
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = BListNode(x);
	//链接
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* end = phead->prev;
	phead->prev = end->prev;
	free(end);
	phead->prev->next = phead;
}

//头插
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newnode = BListNode(x);
	LTNode* next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}

//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* next = phead->next;
	phead->next = next->next;
	phead = next->next->prev;
	free(next);
}

//扩容
LTNode* BListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//查找
LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//在指定位置之前的插入
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newnode = BListNode(x);
	LTNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//在指定位置的删除
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posNext = pos->next;
	LTNode* posPrev = pos->prev;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}
//posPrev		posNext


//销毁空间
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}