#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;				//也可以给-1
								//初始化时，top给的使0，意味着top指向栈顶数据的下一个
								//初始化时，top给的是-1，意味着top指向栈顶数据
	ps->capacity = 0;
}

//释放内存
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//插入数据
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

//删除数据
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//取栈顶数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];

}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//栈的大小
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}