#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDatetype;


typedef struct SListNode
{
	SLTDatetype data;
	struct SListNode* next;
}SLTNode;

//创建空间
SLTNode* BuyListNode(SLTDatetype x);
//打印
void SListPrint(SLTNode* phead);
//尾插
void SListPushBack(SLTNode** pphead, SLTDatetype x);
//头插
void SListPushFront(SLTNode** pphead, SLTDatetype x);
//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);

//查找
SLTNode* SListFind(SLTNode* phead, SLTDatetype x);
//在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDatetype x);
//删除指定位置前的节点
void SListErase(SLTNode** pphead, SLTNode* pos);
//删除指定位置后的节点
void SListEraseAfter(SLTNode* pos);
//销毁
void SListDestroy(SLTNode** pphead);

//在pos位置之后去插入一个节点，这个更适合，也更简单
void SListInsertAfter(SLTNode* pos, SLTDatetype x);



