#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"


//��ʼ��
LTNode* ListInit()
{
	//�����ڱ�λ�ڵ�
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//��ӡ����
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

//β��
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = BListNode(x);
	//����
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* end = phead->prev;
	phead->prev = end->prev;
	free(end);
	phead->prev->next = phead;
}

//ͷ��
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

//ͷɾ
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* next = phead->next;
	phead->next = next->next;
	phead = next->next->prev;
	free(next);
}

//����
LTNode* BListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//����
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

//��ָ��λ��֮ǰ�Ĳ���
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

//��ָ��λ�õ�ɾ��
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


//���ٿռ�
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