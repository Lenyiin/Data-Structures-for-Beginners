#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//打印链表
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//物理图：	内存中真实存储
//			phead


//创建空间
SLTNode* BuyListNode(SLTDatetype x)
{
	//1M=1024KB=1024*1024Byte
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SListPushBack(SLTNode** pphead, SLTDatetype x)
{
	//创建空间
	SLTNode* newnode = BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//头插
void SListPushFront(SLTNode** pphead, SLTDatetype x)
{
	//创建空间
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	//1.没有节点		温柔一点
	//if (*pphead == NULL)
	//{

	//}
	//1.没有节点		粗暴一点的方式
	assert(*pphead != NULL);
	//2.一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}

//头删
void SListPopFront(SLTNode** pphead)
{
	//1.没有节点		温柔一点
	//if (*pphead == NULL)
	//{

	//}
	//1.没有节点		粗暴一点的方式
	assert(*pphead != NULL);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	next = NULL;
}

//查找
SLTNode* SListFind(SLTNode* phead, SLTDatetype x)
{
	SLTNode* cur = phead;
	while (cur)
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

//在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDatetype x)
{
	SLTNode* newnode = BuyListNode(x);

	if (*pphead == pos)
	{
		//头插
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
	
}

//在pos位置之后去插入一个节点，这个更适合，也更简单
void SListInsertAfter(SLTNode* pos, SLTDatetype x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除指定位置前的节点
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead = pos)
	{
		*pphead = pos->next;
		free(pos);
		//或者这里直接调用头删
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

//删除指定位置后的节点
void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//销毁
void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}


