#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//P14-P




//Lesson3--顺序表和链表
//1.线性表
//2.顺序表
//3.链表
//4.顺序表和链表的区别和联系


//1.线性表
//	线性表（linear list）是n个具有相同特性的数据元素的有限序列。线性表是一种在实际中广泛使用的数据结构，常见的线性表：顺序表、链表、栈、队列、字符串...
//	线性表在逻辑上是线性结构，也就是说是连续的一条直线。但是在物理结构上并不一定是最连续的，线性表在物理上存储时，通常以数组和链式结构的形式存储。
//2.顺序表				顺序表就是数组，但是在数组的基础上，他还要求数据是连续存储的，不能跳跃间隔
//2.1 顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组上完成数据的增删查改。


//作业		移除元素
//给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
//不需要使用额外的数组空间，你必须仅使用O(1)的额外空间并原地修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//思路1：找到所有的val，一次挪动数据覆盖删除
//			时间复杂度：O(N^2)	最坏的情况：数组中大部分值甚至全部都是val
//思路2：一次遍历nums数组，把不是val的值，放到tmp数组，再把tmp数组的值拷贝回去
//			时间复杂度：O(N)	空间复杂度：O（N）
//思路3：定义两个变量src和dst，src去找nums数组中不等于val的值，放到dst指向的位置去，再++src，++dst
//			时间复杂度：O(N)	空间复杂度：O（1）
//int removeElement(int* nums, int numSize, int val)
//{
//	int src = 0, dst = 0;
//	while (src < numSize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dst] = nums[src];
//			dst++;
//			src++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dst;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,2,14,5,2,4,5,2,1,5,2,22,3,1,2 };
//	int val = 2;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = removeElement(arr, sz, val);
//	printf("%d\n", ret);
//	return 0;
//}



//作业			去重
//给你一个有序数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须原地修改输入数组，并在使用O（1）额外空间的条件下完成。

/*
int removeDuplicates(int* nums, int numsSize)
{
	int src = 1, dst = 1;
	int count = 1;
	for (int i = 0; i < numsSize-1; i++)
	{
		int src = i + 1, dst = i + 1;
		while (src < numsSize)
		{
			if (nums[i] != nums[src])
			{
				nums[dst] = nums[src];
				src++;
				dst++;
				count++;
			}
			else
			{
				src++;
				count++;
			}
		}
		
	}
	return count++;
}
void print(int* ps, int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", ps[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 1,2,3,4,5,5,4,2,5,3,1,1,8,9,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);

	int ret=removeDuplicates(arr, sz);
	sz = sizeof(arr) / sizeof(arr[0]);
	print(arr,ret);

	return 0;
}

*/				//这段写错了		这个写的是无序数组，半成品状态

//这个是正确答案
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//		return 0;
//	int i = 0, j = 1;
//	int dst = 0;
//	while (j < numsSize)
//	{
//		if (nums[i] == nums[j])
//		{
//			j++;
//		}
//		else
//		{
//			nums[dst] = nums[i];
//			dst++;
//			i = j;
//			j++;
//		}
//	}
//	nums[dst] = nums[i];
//	dst++;
//	return dst;
//}
//void print(int* ps, int sz)
//{
//	for (int i = 0; i < sz; i++)
//		printf("%d ", ps[i]);
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 0,0,1,1,1,2,2,2,3,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//
//	int ret = removeDuplicates(arr, sz);
//	print(arr, ret);
//
//	return 0;
//}


//作业			合并两个有序数组
//给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中元素数目。
//请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列
//思路1：创建一个更大的数组，归并两个数组
//思路2：从后往前比
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int end1 = m - 1, end2 = n - 1;
//	int end = m + n - 1;
//
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}
//void print(int* ps, int sz)
//{
//	for (int i = 0; i < sz; i++)
//		printf("%d ", ps[i]);
//	printf("\n");
//}
//int main()
//{
//	int nums1[] = { 1,1,2,3,8,0,0,0,0,0,0 };
//	int nums2[] = { 2,2,3,5,5,8 };
//	int m = 5;
//	int n = 6;
//	merge(nums1, m, m, nums2, n, n);
//	print(nums1, m + n);
//
//	return 0;
//}


//顺序表优点：
//1.支持随机访问（用下标直接访问第i个）
//	有些算法，需要结构支持随机访问。比如：二分查找、比如优化的快排等等
//顺序表缺陷：
//1.空间不够需要增容，增容是要付出代码
//2.避免频繁扩容，我们满了基本上都是扩2倍，可能会导致一定的空间浪费
//3.顺序表要求数据是从开始位置连续存储，那么我们在头部或者中间位置插入删除数据就需要挪动数据，效率不高
//针对数据表的缺陷，就设计出链表
//优点：
//1.按需申请空间，不用了就释放空间（更合理的使用了空间）
//2.头部中间插入删除数据，不需要挪动数据
//缺点：
//1.每个数据，都要存一个指针去连接后面数据节点
//2.不支持随机访问（用下标直接访问第i个）


//int main()
//{
//
//	int* p1 = malloc(sizeof(int) * 10);
//	int* p2 = realloc(p1,sizeof(int) * 20);
//
//	return 0;
//}


//实参是int，要改变实参，要传int*		函数里解引用去改变
//实参是int*，要改变实参，要传int**



//逻辑结构：想象出来的，更形象，方便理解
//物理结构：在内存中实实在在如何存储的




//单链表的缺陷还是很多的，单纯的单链表增删查改的意义不大
//1.很多OJ题考察的都是单链表
//2.单链表更多的是去更复杂度数据结构的子结构。哈希桶、邻接表
//链表存储数据还要看双向链表。




//作业		移除链表元素
//给你一个链表的头节点head和一个整数val，请你删除链表中所有满足Node.val=val的节点，并返回新的头节点。

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//
//	struct ListNode* prev = NULL, * cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//头删
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//			else
//			{
//				//中间删除
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			//迭代往后走
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
//int main()
//{
//	//方便快速调试OJ代码
//	struct ListNode* test1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* test2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* test3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* test4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	test1->val = 7;
//	test2->val = 7;
//	test3->val = 7;
//	test4->val = 7;
//	test1->next = test2;
//	test2->next = test3;
//	test3->next = test4;
//	test4->next = NULL;						//这份代码拿来测试会很方便
//
//	struct ListNode* head = removeElements(test1, 7);
//
//	return 0;
//}



//在前面插入，会有效率损失




//作业			反转链表
//给你一个单链表的头节点head，请你反转链表，并返回反转后的链表
//思路1：将箭头转向
//思路2：取原链表中节点，头插到newhead新链表中
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
////思路1：
//struct ListNode* removeElements(struct ListNode* head)
//{
//	if (head == NULL)
//		return NULL;
//	//初始条件
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//
//	//迭代
//	while (n2)
//	{
//		//核心逻辑
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if(n3)
//			n3 = n3->next;
//	}
//	return n1;
//}
////思路2：
//struct ListNode* removeElements(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		//头插
//		cur->next = newhead;
//		newhead = cur;
//		//迭代往后走
//		cur = next;
//	}
//	return newhead;
//}



//作业			链表的中间节点
//给定一个头节点为head的非空单链表，返回链表的中间结点。如果有两个中间节点，则返回第二个中间节点。
//思路1：先遍历一遍计数总长度，第二次遍历到一半
//思路2：定义两个指针，慢指针一次走一步，快指针一次走两步

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* slow, * fast;
//	slow = fast = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}



//作业		链表中倒数第k个结点
//输入一个链表，输出该链表中倒数第k个节点
//思路1：遍历第一遍知道有几个，遍历第二遍找到倒数第几个的位置
//思路2：快慢指针，fast先走k步，然后fast和slow指针再一起走

struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	if (pListHead)
	{
		return NULL;
	}

	struct ListNode* slow, * fast;
	slow = fast = pListHead;
	while (k--)						//--k	循环k-1次		k--		循环了k次
	{
		//大于链表的长度
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
