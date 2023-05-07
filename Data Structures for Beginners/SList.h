#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDatetype;


typedef struct SListNode
{
	SLTDatetype data;
	struct SListNode* next;
}SLTNode;

//�����ռ�
SLTNode* BuyListNode(SLTDatetype x);
//��ӡ
void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SLTNode** pphead, SLTDatetype x);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDatetype x);
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);

//����
SLTNode* SListFind(SLTNode* phead, SLTDatetype x);
//��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDatetype x);
//ɾ��ָ��λ��ǰ�Ľڵ�
void SListErase(SLTNode** pphead, SLTNode* pos);
//ɾ��ָ��λ�ú�Ľڵ�
void SListEraseAfter(SLTNode* pos);
//����
void SListDestroy(SLTNode** pphead);

//��posλ��֮��ȥ����һ���ڵ㣬������ʺϣ�Ҳ����
void SListInsertAfter(SLTNode* pos, SLTDatetype x);



