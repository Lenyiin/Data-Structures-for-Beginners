#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;				//Ҳ���Ը�-1
								//��ʼ��ʱ��top����ʹ0����ζ��topָ��ջ�����ݵ���һ��
								//��ʼ��ʱ��top������-1����ζ��topָ��ջ������
	ps->capacity = 0;
}

//�ͷ��ڴ�
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//��������
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realoc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//ɾ������
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//ȡջ������
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];

}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//ջ�Ĵ�С
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}