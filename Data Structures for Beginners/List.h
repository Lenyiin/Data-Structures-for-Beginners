#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//��ʼ��
LTNode* ListInit();

//��ӡ����
void ListPrint(LTNode* phead);

//β��
void ListPushBack(LTNode* phead, LTDateType x);

//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x);

//ͷɾ
void ListPopFront(LTNode* phead);

//����
LTNode* BListNode(LTDateType x);

//����
LTNode* ListFind(LTNode* phead, LTDateType x);

//��ָ��λ��֮ǰ�Ĳ���
void ListInsert(LTNode* pos, LTDateType x);

//��ָ��λ�õ�ɾ��
void ListErase(LTNode* pos);

//���ٿռ�
void ListDestroy(LTNode* phead);