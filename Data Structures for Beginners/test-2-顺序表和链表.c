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


//˳����ŵ㣺
//1.֧��������ʣ����±�ֱ�ӷ��ʵ�i����
//	��Щ�㷨����Ҫ�ṹ֧��������ʡ����磺���ֲ��ҡ������Ż��Ŀ��ŵȵ�
//˳���ȱ�ݣ�
//1.�ռ䲻����Ҫ���ݣ�������Ҫ��������
//2.����Ƶ�����ݣ��������˻����϶�����2�������ܻᵼ��һ���Ŀռ��˷�
//3.˳���Ҫ�������Ǵӿ�ʼλ�������洢����ô������ͷ�������м�λ�ò���ɾ�����ݾ���ҪŲ�����ݣ�Ч�ʲ���
//������ݱ��ȱ�ݣ�����Ƴ�����
//�ŵ㣺
//1.��������ռ䣬�����˾��ͷſռ䣨�������ʹ���˿ռ䣩
//2.ͷ���м����ɾ�����ݣ�����ҪŲ������
//ȱ�㣺
//1.ÿ�����ݣ���Ҫ��һ��ָ��ȥ���Ӻ������ݽڵ�
//2.��֧��������ʣ����±�ֱ�ӷ��ʵ�i����


//int main()
//{
//
//	int* p1 = malloc(sizeof(int) * 10);
//	int* p2 = realloc(p1,sizeof(int) * 20);
//
//	return 0;
//}


//ʵ����int��Ҫ�ı�ʵ�Σ�Ҫ��int*		�����������ȥ�ı�
//ʵ����int*��Ҫ�ı�ʵ�Σ�Ҫ��int**



//�߼��ṹ����������ģ������󣬷������
//����ṹ�����ڴ���ʵʵ������δ洢��




//�������ȱ�ݻ��Ǻܶ�ģ������ĵ�������ɾ��ĵ����岻��
//1.�ܶ�OJ�⿼��Ķ��ǵ�����
//2.������������ȥ�����Ӷ����ݽṹ���ӽṹ����ϣͰ���ڽӱ�
//����洢���ݻ�Ҫ��˫������




//��ҵ		�Ƴ�����Ԫ��
//����һ�������ͷ�ڵ�head��һ������val������ɾ����������������Node.val=val�Ľڵ㣬�������µ�ͷ�ڵ㡣

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
//			//ͷɾ
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//			else
//			{
//				//�м�ɾ��
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			//����������
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
//int main()
//{
//	//������ٵ���OJ����
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
//	test4->next = NULL;						//��ݴ����������Ի�ܷ���
//
//	struct ListNode* head = removeElements(test1, 7);
//
//	return 0;
//}



//��ǰ����룬����Ч����ʧ




//��ҵ			��ת����
//����һ���������ͷ�ڵ�head�����㷴ת���������ط�ת�������
//˼·1������ͷת��
//˼·2��ȡԭ�����нڵ㣬ͷ�嵽newhead��������
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
////˼·1��
//struct ListNode* removeElements(struct ListNode* head)
//{
//	if (head == NULL)
//		return NULL;
//	//��ʼ����
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//
//	//����
//	while (n2)
//	{
//		//�����߼�
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if(n3)
//			n3 = n3->next;
//	}
//	return n1;
//}
////˼·2��
//struct ListNode* removeElements(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		//ͷ��
//		cur->next = newhead;
//		newhead = cur;
//		//����������
//		cur = next;
//	}
//	return newhead;
//}



//��ҵ			������м�ڵ�
//����һ��ͷ�ڵ�Ϊhead�ķǿյ���������������м��㡣����������м�ڵ㣬�򷵻صڶ����м�ڵ㡣
//˼·1���ȱ���һ������ܳ��ȣ��ڶ��α�����һ��
//˼·2����������ָ�룬��ָ��һ����һ������ָ��һ��������

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



//��ҵ		�����е�����k�����
//����һ����������������е�����k���ڵ�
//˼·1��������һ��֪���м����������ڶ����ҵ������ڼ�����λ��
//˼·2������ָ�룬fast����k����Ȼ��fast��slowָ����һ����

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
	while (k--)						//--k	ѭ��k-1��		k--		ѭ����k��
	{
		//��������ĳ���
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
