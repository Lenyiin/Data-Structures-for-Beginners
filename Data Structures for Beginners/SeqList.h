#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��ǿ����Ŀ�ά����
#define N 1000
typedef int SLDataType;				//�Ժ�Ҫ����˳�������ͣ�ֱ�ӽ�double�޸ĳ�int��char����Ҫ������

//��������test-2



//��̬˳���
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;			//��ʾ�����д����˶��ٸ�����
//}SL;

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;			//��ʾ�����д����˶��ٸ�����
	int capacity;		//����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;

//typedef struct SeqList SL;		//���������������������ǵȼ۵�

//�ӿں���			- -			����������STL�ߵģ�������Ҳ���������Ͽ��ߣ��������ѧϰSTL

//��ɾ��ĵȽӿں���

//��ӡ
void SeqListPrint(SL* s1);
//��ʼ��
void SeqListInit(SL* ps);
//��̬�ڴ�����
void SeqListDestory(SL* ps);
//�������
void SeqListCheckCapacity(SL* ps);

//ͷ��	β��	ͷɾ	βɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//...

//��������		�ҵ��˷���xλ���±꣬û�ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);

//ָ��pos���±�λ�ò���
void SeqListInsert(SL* ps,int pos, SLDataType x);

//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);

//�˵�
void menu();

//��̬�ص㣺������˾Ͳ��ò���		ȱ�㣺�����ٵĺ����أ��������ȷ��
//			N��С�˲����ã�N�������˷�

