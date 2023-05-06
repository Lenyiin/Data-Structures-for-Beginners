#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//增强程序的可维护性
#define N 1000
typedef int SLDataType;				//以后要更改顺序表的类型，直接将double修改成int、char等需要的类型

//主函数在test-2



//静态顺序表
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;			//表示数组中储存了多少个数据
//}SL;

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;			//表示数组中储存了多少个数据
	int capacity;		//数组实际能存数据的空间容量是多大
}SL;

//typedef struct SeqList SL;		//这个和上面的那种重命名是等价的

//接口函数			- -			命名风格跟着STL走的，建议大家也跟着我们上课走，方便后续学习STL

//增删查改等接口函数

//打印
void SeqListPrint(SL* s1);
//初始化
void SeqListInit(SL* ps);
//动态内存销毁
void SeqListDestory(SL* ps);
//容量检查
void SeqListCheckCapacity(SL* ps);

//头插	尾插	头删	尾删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//...

//查找数字		找到了返回x位置下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x);

//指定pos的下标位置插入
void SeqListInsert(SL* ps,int pos, SLDataType x);

//删除pos位置的数据
void SeqListErase(SL* ps, int pos);

//菜单
void menu();

//静态特点：如果满了就不让插入		缺点：给多少的合适呢？这个很难确定
//			N给小了不够用，N给大了浪费

