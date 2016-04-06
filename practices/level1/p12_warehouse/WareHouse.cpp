// WareHouse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

FILE *stream;

#define SHOW_LIST 1
#define IMPORT 2
#define EXPORT 3
#define EXIT 4


struct data
{
	char type[128];
	int num;
	data *next,*pre;
};

struct data *cargo, *head=NULL;

void readFromTxt();
void init(int v_operand);
void v_show_list();
void v_import();
void v_export();

int main()
{
	readFromTxt();
	int operand;
	while (1)
	{
		Sleep(2000);
		system("cls");
		printf("�����������\n");
		printf("1:��ʾ����б�\n");
		printf("2:���\n");
		printf("3:����\n");
		printf("4:�˳�����\n");
		scanf_s("%d", &operand);
		system("cls");
		init(operand);
	}
    return 0;
}

void readFromTxt()
{
	freopen_s(&stream ,"WareHouse.txt", "r", stderr);
	cargo = (struct data *)malloc(sizeof(struct data));
	int num;
	while (fscanf_s(stream, "%s", cargo->type,128)!=EOF)
	{
		fscanf_s(stream, "%d", &num);
		cargo->num = num;
		cargo->next = head;
		if (head!=NULL)
			head->pre = cargo;
		head = cargo;
		cargo = (struct data *)malloc(sizeof(struct data));
	}
	//delete(cargo);
}

void init(int v_operand)
{
	switch (v_operand)
	{
	case SHOW_LIST:
		v_show_list();
		break;
	case IMPORT:
		v_import();
		break;
	case EXPORT:
		v_export();
		break;
	case EXIT:
		freopen_s(&stream,"WareHouse.txt", "w", stderr);
		for (struct data *t = head; t != NULL; t = t->next)
		{
			fprintf(stream,"%s\n", t->type);
			fprintf(stream,"%d\n", t->num);
		}
		fclose(stream);
		exit(0);
		break;
	default:
		break;
	}
}

void v_show_list()
{
	for (struct data *t = head; t != NULL; t = t->next)
		printf("�����ͺţ�%s  ����������%d\n",t->type,t->num);
	printf("\n\n");
}

void v_import()
{
	cargo = (struct data *)malloc(sizeof(struct data));
	printf("��������ͺţ�\n");
	scanf_s("%s", cargo->type,128);
	printf("�������������\n");
	scanf_s("%d", &cargo->num);
	cargo->pre = cargo;
	cargo->next = head;
	if (head != NULL)
		head->pre = cargo;
	head = cargo;
	printf("���ɹ���\n\n");
}

bool check(char *t1, char *t2,int len1,int len2)
{
	int tot = 0;
	if (len1 != len2) return false;
	else
		while (*(t1+tot) == *(t2+tot))
		{
			if (tot == len1) return true;
			tot++;
		}
	return false;
}
void v_export()
{
	char type[128];
	printf("�����������ͺţ�\n");
	scanf_s("%s", &type,128);
	for (struct data *t = head; t != NULL; t = t->next)
		if (check(t->type,type,strlen(t->type),strlen(type)))
		{
			if (t == head)
			{
				head = t->next;
				printf("����ɹ���\n\n");
				break;
			}
			if (t->next != NULL)
			{
				t->pre->next = t->next;
				t->next->pre = t->pre;
				printf("����ɹ���\n\n");
				break;
			}
			else
			{
				t->pre->next= NULL;
				printf("����ɹ���\n\n");
				break;
			}
			
		}

}

