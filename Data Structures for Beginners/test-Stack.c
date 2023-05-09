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

	//释放内存
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

	//取数据
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	//释放内存
	StackDestroy(&st);
}



//作业			有效的括号
//给定一个只包含“（”，“）”，“{”，“}”，“[”，“]”的字符串s，判断字符串是否有效。
//有效字符串需满足：1.左括号必须用相同类型的右括号闭合。
//					2.左括号必须以正确的顺序闭合。

bool isValid(char* s)
{
	ST st;
	//初始化
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
			//遇到右括号了，但是栈里面没有数据，说明前面没有左括号，不匹配，返回false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
			{
				//销毁栈
				StackDestroy(&st);
				return false;
			}
			else
			{
				s++;
			}
		}
	}

	bool ret = StackEmpty(&st);			//如果栈不是空，说明栈中还有左括号未出，没有匹配，返回的是false

	//销毁栈
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
