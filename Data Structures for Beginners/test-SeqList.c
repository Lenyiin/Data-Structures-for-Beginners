#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//�������Σ��β���ʵ�εĿ���
//�βεĸı䲻��Ӱ��ʵ��

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1,3);
	SeqListPushBack(&s1,4);
	SeqListPushBack(&s1,5);
	//��ӡ
	SeqListPrint(&s1);
	//βɾ
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	//��ӡ
	SeqListPrint(&s1);

	//����
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
	//��ӡ
	SeqListPrint(&s1);
	
	//ͷ��
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	//��ӡ
	SeqListPrint(&s1);

	//ͷɾ
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	//��ӡ
	SeqListPrint(&s1);

	//��������
	int ret = SeqListFind(&s1, 1);
	printf("%d\n", ret);

	//��ָ��λ�ò���
	SeqListInsert(&s1, 3, 5);
	//��ӡ
	SeqListPrint(&s1);

	//��3��ǰ�����50
	ret = SeqListFind(&s1, 3);
	if (ret != -1)
	{
		SeqListInsert(&s1, ret, 50);
	}
	SeqListPrint(&s1);

	//��ָ��λ�ò���		ģ��β��
	SeqListInsert(&s1, 9, 90);
	//��ӡ
	SeqListPrint(&s1);

	//��ָ��λ�ò���		ģ��ͷ��
	SeqListInsert(&s1, 0, 0);
	//��ӡ
	SeqListPrint(&s1);

	//����
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
	//��ӡ
	SeqListPrint(&s1);

	//ͷ��
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	//��ӡ
	SeqListPrint(&s1);

	SeqListPushBack(&s1, 5);
	//��ӡ
	SeqListPrint(&s1);

	//ɾ��ָ��λ��
	SeqListErase(&s1, 1);
	//��ӡ
	SeqListPrint(&s1);

	//βɾ
	SeqListPopBack(&s1);
	//��ӡ
	SeqListPrint(&s1);

	//ͷɾ
	SeqListPopFront(&s1);
	//��ӡ
	SeqListPrint(&s1);

	//����
	SeqListDestory(&s1);
}

//1.����������ռ�洢 -- ����
//2.���ݱ����Ǵ�ͷ��ʼ�����δ洢

//дһ������ͨѶ¼�Ĳ˵�
void menu()
{
	printf("******************************************\n");
	printf("****        ��ѡ����Ĳ�����>         ****\n");
	printf("****        1.ͷ��      2.ͷɾ        ****\n");
	printf("****        3.β��      4.βɾ        ****\n");
	printf("****        5.��ӡ      0.�˳�        ****\n");
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
			printf("��������Ҫͷ��������֣���0����\n");
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
			printf("��������Ҫβ��������֣���0����\n");
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
			printf("����������������룺\n");
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