#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"



void TestList1()
{
	LTNode* plist = ListInit();
	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	//��ӡ
	ListPrint(plist);

	//βɾ
	ListPopBack(plist);
	ListPopBack(plist);
	//��ӡ
	ListPrint(plist);

	//ͷ��
	ListPushFront(plist, 5);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	//��ӡ
	ListPrint(plist);

	//ͷɾ
	ListPopFront(plist);
	//��ӡ
	ListPrint(plist);

	//����
	LTNode* pos = ListFind(plist, 5);
	if (pos != NULL)
	{
		ListInsert(pos, 50);
	}
	//��ӡ
	ListPrint(plist);


	pos = ListFind(plist, 2);
	if (pos != NULL)
	{
		ListErase(pos);
	}
	//��ӡ
	ListPrint(plist);


	//����
	ListDestroy(plist);
	plist = NULL;
}

//int main()
//{
//	TestList1();
//	return 0;
//}