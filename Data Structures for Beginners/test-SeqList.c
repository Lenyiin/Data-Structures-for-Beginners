#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//函数传参，形参是实参的拷贝
//形参的改变不会影响实参

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1,3);
	SeqListPushBack(&s1,4);
	SeqListPushBack(&s1,5);
	//打印
	SeqListPrint(&s1);
	//尾删
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	//打印
	SeqListPrint(&s1);

	//销毁
	SeqListDestory(&s1);
}

void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	//打印
	SeqListPrint(&s1);
	
	//头插
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	//打印
	SeqListPrint(&s1);

	//头删
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	//打印
	SeqListPrint(&s1);

	//查找数字
	int ret = SeqListFind(&s1, 1);
	printf("%d\n", ret);

	//在指定位置插入
	SeqListInsert(&s1, 3, 5);
	//打印
	SeqListPrint(&s1);

	//在3的前面插入50
	ret = SeqListFind(&s1, 3);
	if (ret != -1)
	{
		SeqListInsert(&s1, ret, 50);
	}
	SeqListPrint(&s1);

	//在指定位置插入		模拟尾插
	SeqListInsert(&s1, 9, 90);
	//打印
	SeqListPrint(&s1);

	//在指定位置插入		模拟头插
	SeqListInsert(&s1, 0, 0);
	//打印
	SeqListPrint(&s1);

	//销毁
	SeqListDestory(&s1);
}

void TestSeqList3()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	//打印
	SeqListPrint(&s1);

	//头插
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	//打印
	SeqListPrint(&s1);

	SeqListPushBack(&s1, 5);
	//打印
	SeqListPrint(&s1);

	//删除指定位置
	SeqListErase(&s1, 1);
	//打印
	SeqListPrint(&s1);

	//尾删
	SeqListPopBack(&s1);
	//打印
	SeqListPrint(&s1);

	//头删
	SeqListPopFront(&s1);
	//打印
	SeqListPrint(&s1);

	//销毁
	SeqListDestory(&s1);
}

//1.连续的物理空间存储 -- 数组
//2.数据必须是从头开始，依次存储

//写一个类似通讯录的菜单
void menu()
{
	printf("******************************************\n");
	printf("****        请选择你的操作：>         ****\n");
	printf("****        1.头插      2.头删        ****\n");
	printf("****        3.尾插      4.尾删        ****\n");
	printf("****        5.打印      0.退出        ****\n");
	printf("******************************************\n");
}

void MenuTest()
{
	SL s1;
	SeqListInit(&s1);
	int input = 1;
	int x;

	
	while (input)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入你要头插入的数字，以0结束\n");
			scanf("%d", &x);
			while (x)
			{
				SeqListPushFront(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			SeqListPopFront(&s1);
			break;
		case 3:
			printf("请输入你要尾插入的数字，以0结束\n");
			scanf("%d", &x);
			while (x)
			{
				SeqListPushBack(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 4:
			SeqListPopBack(&s1);
			break;
		case 5:
			SeqListPrint(&s1);
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	}
	SeqListDestory(&s1);
}

//int main()
//{
//	//TestSeqList1();
//	//TestSeqList2();
//	//TestSeqList3();
//	MenuTest();
//
//	return 0;
//}