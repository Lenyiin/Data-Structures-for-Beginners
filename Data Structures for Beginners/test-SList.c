#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//单链表


void TestSList1()
{
	SLTNode* plist = NULL;
	//尾插
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	//打印
	SListPrint(plist);

	//头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	//打印
	SListPrint(plist);

	//尾删
	SListPopBack(&plist);
	//打印
	SListPrint(plist);

	//头删
	SListPopFront(&plist);
	//打印
	SListPrint(plist);
}
void TestSList2()
{
	SLTNode* plist = NULL;
	//尾插
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);
	//打印
	SListPrint(plist);

	//查找
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
		pos= SListFind(pos->next, 2);
	}
	//修改		把第一个3修改成30
	pos= SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	//打印
	SListPrint(plist);

	//在30的前面 插上一个20
	pos = SListFind(plist, 30);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	//打印
	SListPrint(plist);
	
	//在1的前面 插上一个10
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	//打印
	SListPrint(plist);
	
}

//int main()
//{
//	//TestSList1();
//	TestSList2();
//	return 0;
//}


//实参是int，要改变实参，要传int*		函数里解引用去改变
//实参是int*，要改变实参，要传int**




//单链表的缺陷还是很多的，单纯的单链表增删查改的意义不大
//1.很多OJ题考察的都是单链表
//2.单链表更多的是去更复杂度数据结构的子结构。哈希桶、邻接表
//链表存储数据还要看双向链表。



