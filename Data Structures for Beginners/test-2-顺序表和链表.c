#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//P14-P




//Lesson3--˳��������
//1.���Ա�
//2.˳���
//3.����
//4.˳����������������ϵ


//1.���Ա�
//	���Ա�linear list����n��������ͬ���Ե�����Ԫ�ص��������С����Ա���һ����ʵ���й㷺ʹ�õ����ݽṹ�����������Ա�˳�������ջ�����С��ַ���...
//	���Ա����߼��������Խṹ��Ҳ����˵��������һ��ֱ�ߡ�����������ṹ�ϲ���һ�����������ģ����Ա��������ϴ洢ʱ��ͨ�����������ʽ�ṹ����ʽ�洢��
//2.˳���				˳���������飬����������Ļ����ϣ�����Ҫ�������������洢�ģ�������Ծ���
//2.1 ˳�������һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢����������������ݵ���ɾ��ġ�


//��ҵ		�Ƴ�Ԫ��
//����һ������nums��һ��ֵval������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
//����Ҫʹ�ö��������ռ䣬������ʹ��O(1)�Ķ���ռ䲢ԭ���޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

//˼·1���ҵ����е�val��һ��Ų�����ݸ���ɾ��
//			ʱ�临�Ӷȣ�O(N^2)	�������������д󲿷�ֵ����ȫ������val
//˼·2��һ�α���nums���飬�Ѳ���val��ֵ���ŵ�tmp���飬�ٰ�tmp�����ֵ������ȥ
//			ʱ�临�Ӷȣ�O(N)	�ռ临�Ӷȣ�O��N��
//˼·3��������������src��dst��srcȥ��nums�����в�����val��ֵ���ŵ�dstָ���λ��ȥ����++src��++dst
//			ʱ�临�Ӷȣ�O(N)	�ռ临�Ӷȣ�O��1��
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



//��ҵ			ȥ��
//����һ����������nums������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ�����ɾ����������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�����ԭ���޸��������飬����ʹ��O��1������ռ����������ɡ�

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

*/				//���д����		���д�����������飬���Ʒ״̬

//�������ȷ��
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


//��ҵ			�ϲ�������������
//�����������ǵݼ�˳�����е���������nums1��nums2��������������m��n���ֱ��ʾnums1��nums2��Ԫ����Ŀ��
//����ϲ�nums2��nums1�У�ʹ�ϲ��������ͬ�����ǵݼ�˳������
//˼·1������һ����������飬�鲢��������
//˼·2���Ӻ���ǰ��
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




