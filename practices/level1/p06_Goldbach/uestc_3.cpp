// uestc_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"
#include "iostream"

bool check(int v)
{
	int num_sqrt=(int)sqrt(v);
	for (int i = 2; i < num_sqrt; i++)
		if (v / i*i == v) return false;   //这一句是看v能否被i整除，素数只能被1和自身整除，如果这个判断成立，就返回false
	return true;
}

int main()
{
	for (int i = 2; i <= 100; i += 2)
	{
		for (int j = 1; j < i; j++)
		{
			if (check(j) && check(i - j)) break;  //找到都是质数的直接break
			if (j+1==i)	printf("Nope\n");  //找不到，输出NOPE
				//return 0;

		}
	}
	printf("Yes");
	system("pause");
	return 0;
}

