#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//��ɾ��ĵȽӿں���
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}

//��ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//��̬�ڴ�����
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//�������
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

//ͷ��	β��	ͷɾ	βɾ
//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	//1.����˳��û�пռ�
	//2.�ռ䲻��	����
	//3.�ռ��㹻

	//���û�пռ���߿ռ䲻�㣬������
	SeqListCheckCapacity(ps);

	//�ռ��㹻
	/*ps->a[ps->size] = x;
	ps->size++;*/

	SeqListInsert(ps, ps->size, x);				//ֱ�Ӻ�������
}

//βɾ
void SeqListPopBack(SL* ps)
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;				//���Բ�Ҫ
	//	ps->size--;
	//}
	//����		���������ֶ϶���һ�������ã����������Ƕδ�����size=0���ʲô�����������������size=0ʱ��ᱨ����ʾ��
	/*assert(ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size-1);						//��������
}

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//���û�пռ���߿ռ䲻�㣬������
	SeqListCheckCapacity(ps);
	//Ų������
	/*int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;*/

	SeqListInsert(ps, 0, x);			//ָ��λ�ò��뺯��������ͷ��
}

//ͷɾ
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
	SeqListErase(ps, 0);				//��������
}

//��������		�ҵ��˷���xλ���±꣬û�ҵ�����-1
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

//ָ�����±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//����Ĵ���ʽ
	//if (pos > ps->size || ps->capacity)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	//�����Ĵ���ʽ
	assert(pos >= 0 && pos <= ps->size);

	//���û�пռ���߿ռ䲻�㣬������
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

//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos)
{
	//�����Ĵ���ʽ
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}