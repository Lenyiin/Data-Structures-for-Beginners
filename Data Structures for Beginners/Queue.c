#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//销毁
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

//尾插数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//增加新节点
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

//删除数据
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

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//里面还有多少个数据
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

//判断是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
