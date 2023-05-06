#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//增删查改等接口函数
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}

//打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//动态内存销毁
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//容量检查
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//头插	尾插	头删	尾删
//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//1.整个顺序没有空间
	//2.空间不够	扩容
	//3.空间足够

	//如果没有空间或者空间不足，就扩容
	SeqListCheckCapacity(ps);

	//空间足够
	/*ps->a[ps->size] = x;
	ps->size++;*/

	SeqListInsert(ps, ps->size, x);				//直接函数复用
}

//尾删
void SeqListPopBack(SL* ps)
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;				//可以不要
	//	ps->size--;
	//}
	//或者		和上面那种断定其一样的作用，不过上面那段代码在size=0后就什么都不做，下面代码在size=0时候会报错，提示你
	/*assert(ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size-1);						//函数复用
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//如果没有空间或者空间不足，就扩容
	SeqListCheckCapacity(ps);
	//挪动数据
	/*int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;*/

	SeqListInsert(ps, 0, x);			//指定位置插入函数来进行头插
}

//头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;
	SeqListErase(ps, 0);				//函数复用
}

//查找数字		找到了返回x位置下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;

}

//指定的下标位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//温柔的处理方式
	//if (pos > ps->size || ps->capacity)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	//暴力的处理方式
	assert(pos >= 0 && pos <= ps->size);

	//如果没有空间或者空间不足，就扩容
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//删除pos位置的数据
void SeqListErase(SL* ps, int pos)
{
	//暴力的处理方式
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}