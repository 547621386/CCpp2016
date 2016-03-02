// uestc_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "windows.h"
using namespace std;

int n;

int two(int r, int v,int n)   //������
{
	if (v == 0) return 0;
	if (v == 1) return r;
	if ((v & 1) == 1)
	{
		int num = two(r, v / 2,n);
		return (num*num*r) % n;
	}
	if ((v & 1) == 0)
	{
		int num = two(r, v / 2,n);
		return (num*num) % n;
	}
}
int main()
{
	SYSTEMTIME sys1,sys2;
	GetLocalTime(&sys1);
	int t1 = time(0);
	srand(t1);
	for (n = 3; n <= 1000; n++)
	{
		
		bool flag = false;
		for (int i = 1; i <= 3; i++)
		{
			int r;
			do {
				r = rand() % n;
			} while (r < 2);
			//printf("rand:%d\n", r);
			if (two(r, n - 1,n) != 1) //����С����
			{
				flag = true;
				break;
			}
			if (flag) break;
			if (flag==false && i == 3) printf("%d\n", n);

		}
	}
	GetLocalTime(&sys2);
	printf("milliseconds:%d", sys2.wMilliseconds - sys1.wMilliseconds);
	system("pause");
	return 0;
}


