#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//������


void TestSList1()
{
	SLTNode* plist = NULL;
	//β��
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	//��ӡ
	SListPrint(plist);

	//ͷ��
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	//��ӡ
	SListPrint(plist);

	//βɾ
	SListPopBack(&plist);
	//��ӡ
	SListPrint(plist);

	//ͷɾ
	SListPopFront(&plist);
	//��ӡ
	SListPrint(plist);
}
void TestSList2()
{
	SLTNode* plist = NULL;
	//β��
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);
	//��ӡ
	SListPrint(plist);

	//����
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("��%d��pos�ڵ㣺%p->%d\n", i++, pos, pos->data);
		pos= SListFind(pos->next, 2);
	}
	//�޸�		�ѵ�һ��3�޸ĳ�30
	pos= SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	//��ӡ
	SListPrint(plist);

	//��30��ǰ�� ����һ��20
	pos = SListFind(plist, 30);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	//��ӡ
	SListPrint(plist);
	
	//��1��ǰ�� ����һ��10
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	//��ӡ
	SListPrint(plist);
	
}

//int main()
//{
//	//TestSList1();
//	TestSList2();
//	return 0;
//}


//ʵ����int��Ҫ�ı�ʵ�Σ�Ҫ��int*		�����������ȥ�ı�
//ʵ����int*��Ҫ�ı�ʵ�Σ�Ҫ��int**




//�������ȱ�ݻ��Ǻܶ�ģ������ĵ�������ɾ��ĵ����岻��
//1.�ܶ�OJ�⿼��Ķ��ǵ�����
//2.������������ȥ�����Ӷ����ݽṹ���ӽṹ����ϣͰ���ڽӱ�
//����洢���ݻ�Ҫ��˫������



