#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue1()
{
	Queue q;
	//≥ı ºªØ
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int main()
{
	TestQueue1();

	return 0;
}