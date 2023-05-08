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

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	if (pListHead)
//	{
//		return NULL;
//	}
//
//	struct ListNode* slow, * fast;
//	slow = fast = pListHead;
//	while (k--)						//--k	循环k-1次		k--		循环了k次
//	{
//		//大于链表的长度
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}



//作业			合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	struct ListNode* head = NULL, * tail = NULL;
//	//如果其中一个链表为NULL，就返回另一个
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//
//	//先做头
//	if (l1->val < l2->val)
//	{
//		head = tail = l1;
//		l1 = l1->next;
//	}
//	else
//	{
//		head = tail = l2;
//		l2 = l2->next;
//	}
//
//	//再尾插
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//
//			tail->next = l1;
//			tail = tail->next;
//			l1 = l1->next;
//		}
//		else
//		{
//
//			tail->next = l2;
//			tail = tail->next;
//			l2 = l2->next;
//		}
//	}
//	if (l1 != NULL)
//	{
//		tail->next = l1;
//	}
//	else
//	{
//		tail->next = l2;
//	}
//	return head;
//}


//改成具有哨兵位的头
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	struct ListNode* head = NULL, * tail = NULL;
//	//如果其中一个链表为NULL，就返回另一个
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//
//	//带一个哨兵位的头节点
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//
//	//再尾插
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//
//			tail->next = l1;
//			tail = tail->next;
//			l1 = l1->next;
//		}
//		else
//		{
//
//			tail->next = l2;
//			tail = tail->next;
//			l2 = l2->next;
//		}
//	}
//	if (l1 != NULL)
//	{
//		tail->next = l1;
//	}
//	else
//	{
//		tail->next = l2;
//	}
//	struct ListNode* list = head->next;
//	free(head);
//	return list;
//}

//力扣链接：https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/submissions/



//作业		链表分割
//现有一链表的头指针ListNode* pHead,给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表头指针

//C++兼容C的语法

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* partition(struct ListNode* pHead, int x)
//{
//	struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
//	//开一个哨兵位头节点，方便尾插
//	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	lessTail->next = NULL;
//	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterTail->next = NULL;
//
//	struct ListNode* cur = pHead;
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = cur;
//		}
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = cur;
//		}
//		cur = cur->next;
//	}
//	greaterTail->next = NULL;
//	lessTail->next = greaterHead->next;
//	struct ListNode* newHead = lessHead->next;
//	free(lessHead);
//	free(greaterHead);
//	return newHead;
//}

//力扣链接：https://leetcode.cn/problems/partition-list-lcci/submissions/
//牛客链接：https://www.nowcoder.com/questionTerminal/0e27e0b064de4eacac178676ef9c9d70



//作业			链表的回文结构
//对于一个链表，请设计一个时间复杂度为O（n）额外空间复杂度为O（1）的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900.
//struct ListNode {
//	int val;
//	struct ListNode* next;
//}; 
//
//struct ListNode* chkPalindrome(struct ListNode* A)
//{
//	struct ListNote* mid = middleNode(A);
//	struct ListNote* rHead = reverseList(mid);
//
//	struct ListNode* curA = A;
//	struct ListNode* curR = rHead;
//	while (curA && curR)
//	{
//		if (curA->val != curR->val)
//		{
//			return 0;
//		}
//		else
//		{
//			curA = curA->next;
//			curR = curR->next;
//		}
//	}
//	return 1;
//}



//作业			相交链表
//给你两个单链表的头节点headA和headB，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回NULL。
//1.判断两个链表是否相交
//2.如果相交，求交点
//思路1：依次取A链表中的每个节点跟B链表中的所有节点比较，如果有地址相同的结点，就是相交，第一个相同的就是交点  暴力求解  穷举法  O（N^2）
//思路2：先找尾，尾结点相同，就是相交，尾节点不相同，就是不相交。
//		 再找交点，长的链表先走（长度差）步，再同时走，第一个相同就是交点。
//#include<stdlib.h>
//struct ListNode {
//	int val;
//	struct ListNode* next;
//}; 
//
//struct ListNode* getIntrsectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//	struct ListNode* tailA = headA;
//	struct ListNode* tailB = headB;
//	int lenA = 1;
//	int lenB = 1;
//	while (tailA->next)
//	{
//		lenA++;
//		tailA = tailA->next;
//	}
//	while (tailB->next)
//	{
//		lenB++;
//		tailB = tailB->next;
//	}
//	//不相交
//	if (tailA != tailB)
//	{
//		return NULL;
//	}
//	int gas = abs(lenA - lenB);			//abs()			求绝对值		#include<stdlib.h>
//	//长的先走差距步，再同时走找交点
//	struct ListNode* longList = headA;
//	struct ListNode* shortList = headA;
//	if (lenA < lenB)
//	{
//		shortList = headA;
//		longList = headB;
//	}
//	while (gas--)
//	{
//		longList = longList->next;
//	}
//	while (longList != shortList)
//	{
//		longList = longList->next;
//		shortList = shortList->next;
//	}
//	return longList;
//}
//力扣没通过		不知道哪里有问题




//作业		环形链表
//给定一个链表，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。
//为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果pos是-1，则在该链表中没有环。
//注：pos不作为参数进行传递，仅仅是为了标识链表的实际情况。
//思路1：快慢指针，slow和fast指向链表的开始。slow一次走一步，fast一次走两步。不带环，fast就会为空，带环，fast就会在环里追上slow

//struct ListNode {
//	int val;
//	struct ListNode* next;
//}; 
//struct ListNode* hasCycle(struct ListNode* head)
//{
//	struct ListNode* slow, * fast;
//	slow = fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			//相遇
//			struct ListNode* meet = slow;
//			//公式证明，在相遇点出发，和起始点出发，会在入环点相遇
//			while (meet != head)
//			{
//				meet = meet->next;
//				head = head->next;
//			}
//			return meet;
//		}
//	}
//	//不带环
//	return NULL;
//}

//slow一次走一步，fast一次走两步，一定会相遇。
//分析证明：第一步：fast一定是先进环，这时slow走了入环前距离的一半
//			第二步：随着slow进环，fast已经在环里走了一段，走了多少跟环的大小有关系。
//			第三步：假设slow进环的时候，slow跟fast的距离是N，fast开始追slow，slow每次走1步，fast每次走2步，它们之间的距离每次减少1步。


//如何找入口点
//第一步：slow走1步，fast走2步，一定会相遇。
//第二步：一个指针从相遇点开始走，一个指针从链表头开始走，他们会在环的入口点相遇。
//分析证明：追上相遇过程中，慢指针走的距离：L+X
//							快指针走的距离：L+N*C+X
//			且快指针走的路程是慢指针的2倍 ：2（L+X）=L+N*C+X			L=N*C-X			L=(N-1)*C+C-X		所以会相遇

//思路2：先找到交点，在交点处断开，然后变成了上一个题找交点问题



//作业			复制带随即指针的链表
//给你一个长度为n的链表，每个节点包含一个额外增加的随机指针random，该指针可以指向链表中的任何结点或空结点
//构造这个链表的深拷贝。深拷贝应该正好由n个全新节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的next指针和random指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//复制链表中的指针都不应该指向原链表中的节点

//struct ListNode {
//	int val;
//	struct ListNode* next;
//	struct ListNode* random;
//};
//struct ListNode* copyRandomList(struct ListNode* head)
//{
//	//1.拷贝节点，插入原节点的后面
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
//		copy->val = cur->val;
//		//插入copy节点
//		copy->next = cur->next;
//		cur->next = copy;
//
//		cur = copy->next;
//	}
//	//2.根据源节点，处理copy节点的random
//	cur = head;
//	while (cur)
//	{
//		struct ListNode* copy = cur->next;
//		if (cur->random == NULL)
//		{
//			copy->random = NULL;
//		}
//		else
//		{
//			copy->random = cur->random->next;
//		}
//		cur = copy->next;
//	}
//	//3.把拷贝节点解下来，链接成新链表
//	struct ListNode* copyHead = NULL, * copyTail = NULL;
//	cur = head;
//	while (cur)
//	{
//		struct ListNode* copy = cur->next;
//		struct ListNode* next = copy->next;
//
//		if (copyTail == NULL)
//		{
//			copyHead = copyTail = copy;
//		}
//		else
//		{
//			copyTail->next = copy;
//			copyTail = copy;
//		}
//		cur->next = next;
//	}
//}










//双向链表
//单	双
//带头	不带头
//循环	非循环

//1.无头单相非循环链表：结构简单，一般不会单独用来存数据。实际中更多的是作为其他数据结构的子结构，如哈希桶、图的邻接表等等。另外这种结构在笔试面试中出现很多。
//2.带头双向循环链表：结构最复杂，一般用在单独存储数据。实际中使用的链表数据结构，都是带头双向循环链表。
//	另外，这个结构虽然结构复杂，但是使用代码实现以后会发现结构会带来很多优势，实现反而简单了，后面我们代码实现了就知道了。





//顺序表和链表
//这两个结构各有优势，很难说谁更优？
//严格他们两，相辅相成的两个结构

//顺序表优点：	1.支持随机访问。需要随机访问结构支持算法可以很好的适用
//				2.CPU高速缓存命中率更高
//顺序表缺点：	1.头部中部插入、删除时间效率低。O（N）
//				2.连续的物理空间，空间不够了以后需要增容。
//				a.增容有一定程度的消耗。b.为了避免频繁增容，一般我们都按倍数去增容，用不完可能存在一定的空间浪费。

//链表（双向带头循环链表）的优点：	1.任意位置插入删除，效率高。O（1）	2.按需申请释放空间。
//链表（双向带头循环链表）的缺点：	1.不支持随机访问。（用下表访问）。意味着：一些排序，二分查找等在这种结构上不适应。
//									2.链表存储一个值，同时要存链接指针，也有一定的消耗。
//									3.CPU高速缓存命中率更低
