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




