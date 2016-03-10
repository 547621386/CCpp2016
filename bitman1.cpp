// bitman1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
int p = 0,head = 0;
struct data
{
	string name,tel;
	int nex,pre;
}person[1000];

void add(string name, string tel)
{
	p++;
	person[p].name = name;
	person[p].tel = tel;
	person[p].nex = head;
	person[head].pre = p;
	head = p;
}

void search(int v, string st)
{
	if (v == 1)
		for (int t = head; t;t=person[t].nex)
			if (person[t].name == st)
			{
				cout << "����:" << person[t].name << endl;
				cout << "����:" << person[t].tel << endl<< endl;
			}
	if (v == 2)
		for (int t = head; t; t = person[t].nex)
			if (person[t].tel == st)
			{
				cout << "����:" << person[t].name << endl;
				cout << "����:" << person[t].tel << endl<< endl;
			}
}

void printall()
{
	for (int t = head; t; t = person[t].nex)
		{
			cout << "����:" << person[t].name << endl;
			cout << "����:" << person[t].tel << endl<<endl;
		}
}

void del(int v, string st)
{
	if (v == 1)
		for (int t = head; t; t = person[t].nex)
			if (person[t].name == st)
			{
				person[person[t].pre].nex = person[t].nex;
				person[person[t].nex].pre = person[t].pre;
			}
	if (v == 2)
		for (int t = head; t; t = person[t].nex)
			if (person[t].tel == st)
			{
				person[person[t].pre].nex = person[t].nex;
				person[person[t].nex].pre = person[t].pre;
			}
}

int main()
{
	int n,o;
	string name, tel;
	while (1)
	{
		printf("\n\n����ָ��:\n");
		printf("1.���\n");
		printf("2.��ѯ\n");
		printf("3.�г�������Ϣ\n");
		printf("4.ɾ��\n");
		cin >> n;
		switch (n)
		{
		case 1:
			printf("��������:\n");
			cin >> name;
			printf("����绰����:\n");
			cin >> tel;
			add(name, tel);
			break;
		case 2:
			printf("����1--��������ѯ  2--�Ե绰�����ѯ\n");
			cin >> o;
			if (o == 1)
			{
				printf("��������:\n");
				cin >> name;
				search(1,name);
			}
			if (o == 2)
			{
				printf("�������:\n");
				cin >> tel;
				search(2,tel);
			}
			break;
		case 3:
			printall();
			break;
		case 4:
			printf("��������ɾ���˵���Ϣ 1--������ʽ 2--���뷽ʽ\n");
			cin >> o;
			if (o == 1)
			{
				printf("��������:\n");
				cin >> name;
				del(1, name);
			}
			if (o == 2)
			{
				printf("�������:\n");
				cin >> tel;
				del(2, tel);
			}
		default:
			break;
		}
	}
    return 0;
}

