// uestc_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "ctime"
using namespace std;

int n;

int two(int r, int v)   //������
{
	if (v == 1) return r;
	if ((v & 1) == 1)
	{
		int num = two(r, v / 2);
		return (num*num*r) % n;
	}
	if ((v & 1) == 0)
	{
		int num = two(r, v / 2);
		return (num*num) % n;
	}
}
int main()
{
	
	scanf_s("%d", &n);
	srand(time(0));
	for (int i = 1; i <= 3; i++)
	{
		int r = rand()/100+11;
		if (two(r, n - 1) != 1) //����С����
		{
			printf("Not");
			system("pause");
			return 0;
		}
		
	}
	printf("Yes");
	system("pause");
    return 0;
}

