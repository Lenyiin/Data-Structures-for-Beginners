#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"


void TestStack1()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	

	printf("%d", StackTop(&st));

	//�ͷ��ڴ�
	StackDestroy(&st);
}

void TestStack2()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//ȡ����
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	//�ͷ��ڴ�
	StackDestroy(&st);
}



//��ҵ			��Ч������
//����һ��ֻ����������������������{������}������[������]�����ַ���s���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺1.�����ű�������ͬ���͵������űպϡ�
//					2.�����ű�������ȷ��˳��պϡ�

bool isValid(char* s)
{
	ST st;
	//��ʼ��
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
			s++;
		}
		else
		{
			//�����������ˣ�����ջ����û�����ݣ�˵��ǰ��û�������ţ���ƥ�䣬����false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
			{
				//����ջ
				StackDestroy(&st);
				return false;
			}
			else
			{
				s++;
			}
		}
	}

	bool ret = StackEmpty(&st);			//���ջ���ǿգ�˵��ջ�л���������δ����û��ƥ�䣬���ص���false

	//����ջ
	StackDestroy(&st);
	return ret;
}


//int main()
//{
//	//TestStack1();
//	TestStack2();
//
//	return 0;
//}
