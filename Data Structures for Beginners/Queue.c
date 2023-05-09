#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//����
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//β������
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//�����½ڵ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//ɾ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QueueNode* next =pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail == NULL;
	}
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//���滹�ж��ٸ�����
int QueueSize(Queue* pq)
{
	assert(pq);

	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
