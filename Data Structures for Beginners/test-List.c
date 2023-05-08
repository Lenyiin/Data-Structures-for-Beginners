#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"



void TestList1()
{
	LTNode* plist = ListInit();
	//尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	//打印
	ListPrint(plist);

	//尾删
	ListPopBack(plist);
	ListPopBack(plist);
	//打印
	ListPrint(plist);

	//头插
	ListPushFront(plist, 5);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	//打印
	ListPrint(plist);

	//头删
	ListPopFront(plist);
	//打印
	ListPrint(plist);

	//查找
	LTNode* pos = ListFind(plist, 5);
	if (pos != NULL)
	{
		ListInsert(pos, 50);
	}
	//打印
	ListPrint(plist);


	pos = ListFind(plist, 2);
	if (pos != NULL)
	{
		ListErase(pos);
	}
	//打印
	ListPrint(plist);


	//销毁
	ListDestroy(plist);
	plist = NULL;
}

//int main()
//{
//	TestList1();
//	return 0;
//}