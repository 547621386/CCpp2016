// uestc_3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "math.h"
#include "iostream"

bool check(int v)
{
	for (int i = 2; i < (int)sqrt(v); i++)
		if (v / i*i == v) return false;
	return true;
}

int main()
{
	for (int i = 2; i <= 100; i += 2)
	{
		for (int j = 1; j < i; j++)
		{
			if (check(j) && check(i - j)) break;  //�ҵ�����������ֱ��break
			if (j+1==i)	printf("Nope\n");  //�Ҳ��������NOPE
				//return 0;

		}
	}
	printf("Yes");
	system("pause");
	return 0;
}

