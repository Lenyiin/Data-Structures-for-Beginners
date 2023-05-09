#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"


//P45-P


//1.ջ
//1.1 ջ�ĸ���ṹ
//	ջ����һ����������Ա���ֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز������������ݲ����ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ס�
//		ջ�е�����Ԫ�����غ���ȳ�LIFO��Last In First Out����ԭ��			����ȳ�
//	ѹջ��ջ�Ĳ������������ջ/ѹջ/��ջ����������ջ����
//	��ջ��ջ��ɾ������������ջ��������Ҳ��ջ����

//����ջ������ṹ����		β��βɾЧ�ʸ�
//��ʽջ�������β��ջ����β��βɾ��Ҫ��Ƴ�˫����������ɾ������Ч�ʵ�
//		  �����ͷ��ջ����ͷ��ͷɾ���Ϳ�����Ƴɵ�����



//��ҵ			��Ч������
//����һ��ֻ����������������������{������}������[������]�����ַ���s���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺1.�����ű�������ͬ���͵������űպϡ�
//					2.�����ű�������ȷ��˳��պϡ�
//bool isValid(char* s)
//{
//	ST st;
//	//��ʼ��
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
//			//�����������ˣ�����ջ����û�����ݣ�˵��ǰ��û�������ţ���ƥ�䣬����false
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
//				//����ջ
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
//	bool ret = StackEmpty(&st);			//���ջ���ǿգ�˵��ջ�л���������δ����û��ƥ�䣬���ص���false
//
//	//����ջ
//	StackDestroy(&st);
//	return ret;
//}




//2.����
//2.1 ���еĸ���ṹ
//	���У�ֻ������һ�˽��в������ݲ���������һ�˽���ɾ�����ݲ������������Ա����о����Ƚ��ȳ�FIFO��First In First Out��
//	����У����в��������һ�˳�Ϊ��β			����<--						<--���
//	�����У�����ɾ��������һ��Ϊ��ͷ					��ͷ			��β
//2.2 ���е�ʵ��

//Ӧ�ã���Ż���



//��ҵ			�ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop��empty����
//ʵ��MyStack�ࣺ	void push(int x)��Ԫ��xѹ��ջ����
//					int pop�����Ƴ�������ջ��Ԫ��
//					int top��������ջ��Ԫ��
//					boolean empty�������ջ�ǿյģ�����true�����򣬷���false
//	���ܸı���нṹ��ֻ��ȥ���ö����ṩ�Ľӿں���ʵ�֡�

//����˼·��1.�����ݣ�����Ϊ�յĶ����롢������һ������Ϊ��
//			2.�����ݵ�ʱ�����γ���ͷ�����ݣ�ת����һ�����б��档ֻʣ���һ��ʱ��pop����


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
//�������ӣ�	https://leetcode.cn/problems/implement-stack-using-queues/submissions/




//��ҵ����ջʵ�ֶ���
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//ʵ�� MyQueue �ࣺ
//	1.void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//	2.int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//	3.int peek() ���ض��п�ͷ��Ԫ��
//	4.boolean empty() �������Ϊ�գ����� true �����򣬷��� false

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
	//���popST��û�����ݣ���pushST�����ݵ���ȥ����ʱ��popST�е����ݾͷ����Ƚ��ȳ���˳����
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
	//���popST��û�����ݣ���pushST�����ݵ���ȥ����ʱ��popST�е����ݾͷ����Ƚ��ȳ���˳����
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

//�������ӣ�	https://leetcode.cn/problems/implement-queue-using-stacks/




//��ҵ�����ѭ������
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ���FIFO���Ƚ��ȳ���ԭ��
//���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����
//һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//���ʵ��Ӧ��֧�����²�����
//	1.MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//	2.Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//	3.Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//	4.enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//	5.deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//	6.isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//	7.isFull() : ���ѭ�������Ƿ�������

//�������ӣ�	https://leetcode.cn/problems/design-circular-queue/

//1.�����Ƚ��ȳ�
//2.�ռ��С�ǹ̶���
//�ص㣺ѭ�����У�����ʹ������ʵ�ֻ�������ʵ�֣���Ҫ�࿪һ���ռ䣬
//		Ҳ����ζ�ţ�Ҫ��һ����K�����ݵ�ѭ�����У�Ҫ��k+1���ռ䣬�����޷�ʵ���пպ�������


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