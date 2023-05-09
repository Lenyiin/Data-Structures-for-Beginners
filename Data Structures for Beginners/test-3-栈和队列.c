#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"


//P45-P


//1.栈
//1.1 栈的概念及结构
//	栈：是一种特殊的线性表，其只允许在固定的一端进行插入和删除元素操作。进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。
//		栈中的数据元素遵守后进先出LIFO（Last In First Out）的原则。			后进先出
//	压栈：栈的插入操作叫做进栈/压栈/入栈，入数据在栈顶。
//	出栈：栈的删除操作叫做出栈。出数据也在栈顶。

//数组栈：这个结构更好		尾插尾删效率高
//链式栈：如果用尾做栈顶，尾插尾删，要设计成双向链表，否则删除数据效率低
//		  如果用头做栈顶，头插头删，就可以设计成单链表。



//作业			有效的括号
//给定一个只包含“（”，“）”，“{”，“}”，“[”，“]”的字符串s，判断字符串是否有效。
//有效字符串需满足：1.左括号必须用相同类型的右括号闭合。
//					2.左括号必须以正确的顺序闭合。
//bool isValid(char* s)
//{
//	ST st;
//	//初始化
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			//遇到右括号了，但是栈里面没有数据，说明前面没有左括号，不匹配，返回false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
//			{
//				//销毁栈
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//
//	bool ret = StackEmpty(&st);			//如果栈不是空，说明栈中还有左括号未出，没有匹配，返回的是false
//
//	//销毁栈
//	StackDestroy(&st);
//	return ret;
//}




//2.队列
//2.1 队列的概念及结构
//	队列：只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表，队列具有先进先出FIFO（First In First Out）
//	入队列：进行插入操作的一端称为队尾			出队<--						<--入队
//	出队列：进行删除操作的一端为队头					队头			队尾
//2.2 队列的实现

//应用：抽号机，



//作业			用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop、empty）。
//实现MyStack类：	void push(int x)将元素x压入栈顶。
//					int pop（）移除并返回栈顶元素
//					int top（）返回栈顶元素
//					boolean empty（）如果栈是空的，返回true；否则，返回false
//	不能改变队列结构，只能去调用队列提供的接口函数实现。

//核心思路：1.入数据，往不为空的队列入、保持另一个队列为空
//			2.出数据的时候，依次出队头的数据，转移另一个队列保存。只剩最后一个时，pop掉。


typedef struct {
	Queue q1;
	Queue q2;
}MyStack;


MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);

	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
//力扣链接：	https://leetcode.cn/problems/implement-stack-using-queues/submissions/




//作业：用栈实现队列
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//	1.void push(int x) 将元素 x 推到队列的末尾
//	2.int pop() 从队列的开头移除并返回元素
//	3.int peek() 返回队列开头的元素
//	4.boolean empty() 如果队列为空，返回 true ；否则，返回 false

typedef struct {
	ST pushST;
	ST popST;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj) {
	//如果popST中没有数据，将pushST的数据导过去，此时。popST中的数据就符合先进先出的顺序了
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	//如果popST中没有数据，将pushST的数据导过去，此时。popST中的数据就符合先进先出的顺序了
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}

//力扣链接：	https://leetcode.cn/problems/implement-queue-using-stacks/




//作业：设计循环队列
//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于FIFO（先进先出）原则
//并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，
//一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//你的实现应该支持如下操作：
//	1.MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//	2.Front : 从队首获取元素。如果队列为空，返回 - 1 。
//	3.Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//	4.enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//	5.deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//	6.isEmpty() : 检查循环队列是否为空。
//	7.isFull() : 检查循环队列是否已满。

//力扣链接：	https://leetcode.cn/problems/design-circular-queue/

//1.符合先进先出
//2.空间大小是固定的
//重点：循环队列，无论使用数组实现还是链表实现，都要多开一个空间，
//		也就意味着，要是一个存K个数据的循环队列，要开k+1个空间，否则无法实现判空和判满。


typedef struct {
	int* a;
	int front;
	int tail;
	int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	obj->a[obj->tail] = value;
	obj->tail++;
	obj->tail %= (k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front++;
	obj->front %= (k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

}

int myCircularQueueRear(MyCircularQueue* obj) {

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {

}