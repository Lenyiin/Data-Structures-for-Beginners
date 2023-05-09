#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestroy(Queue* pq);

//入数据
void QueuePush(Queue* pq, QDataType x);

//出数据
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//里面还有多少个数据
int QueueSize(Queue* pq);

//判断是否为空
bool QueueEmpty(Queue* pq);