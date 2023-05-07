#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//��ӡ����
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

//����ͼ��	�ڴ�����ʵ�洢
//			phead


//�����ռ�
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

//β��
void SListPushBack(SLTNode** pphead, SLTDatetype x)
{
	//�����ռ�
	SLTNode* newnode = BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β�ڵ�
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDatetype x)
{
	//�����ռ�
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	//1.û�нڵ�		����һ��
	//if (*pphead == NULL)
	//{

	//}
	//1.û�нڵ�		�ֱ�һ��ķ�ʽ
	assert(*pphead != NULL);
	//2.һ���ڵ�
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

//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	//1.û�нڵ�		����һ��
	//if (*pphead == NULL)
	//{

	//}
	//1.û�нڵ�		�ֱ�һ��ķ�ʽ
	assert(*pphead != NULL);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	next = NULL;
}

//����
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

//��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDatetype x)
{
	SLTNode* newnode = BuyListNode(x);

	if (*pphead == pos)
	{
		//ͷ��
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
	
}

//��posλ��֮��ȥ����һ���ڵ㣬������ʺϣ�Ҳ����
void SListInsertAfter(SLTNode* pos, SLTDatetype x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��ָ��λ��ǰ�Ľڵ�
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead = pos)
	{
		*pphead = pos->next;
		free(pos);
		//��������ֱ�ӵ���ͷɾ
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

//ɾ��ָ��λ�ú�Ľڵ�
void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//����
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


