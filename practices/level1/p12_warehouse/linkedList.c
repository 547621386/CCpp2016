//by Eric linkedList.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

pItemNode finitialize(void)
{
	pItemNode newHead = _setupNewItem();
	return newHead;
}

int finsertNode(pItemNode head, int num2insert, int inputState, item *baseItem)
{
	switch (inputState)
	{
	case 0:
	{
		pItemNode pBottomNode = _checkIsNode(head, num2insert);
		if (pBottomNode != NULL)
		{
			pBottomNode->next = _getInfo2Node((_setupNewItem()), inputState, baseItem);
			return 1;
		}
		break;
	}

	default:
	{
		pItemNode pUpNode = _checkIsNode(head, num2insert);
		//������һ����ָ��
		if (pUpNode != NULL)
		{
			pItemNode tempNextNode = pUpNode->next;
			pUpNode->next = _getInfo2Node(_setupNewItem(), inputState, baseItem);
			//��������
			pUpNode = pUpNode->next;
			pUpNode->next = tempNextNode;
			return 1;
		}
	}
	}

	return 0;
}

int fdeleteNode(pItemNode head, int num2delete)
{
	if (_checkIsNode(head, num2delete))
	{
		pItemNode pUpNode, pDeNode;
		if (num2delete == 1)
			pUpNode = head;
		else
		{
			pUpNode = _checkIsNode(head, num2delete - 1);
		}
		pDeNode = pUpNode->next;
		//��ȡ��ɾ���ڵ�����νڵ�ĵ�ַ
		pUpNode->next = pDeNode->next;
		//�߳���ɾ���ڵ�
		free(pDeNode);
		//ɾ���ڵ�
		return 1;
	}
	return 0;
}

int ffindNode(pItemNode head, item compareItem)
{
	int count = 0;
	pItemNode current = head;
	while (current->next != NULL)
	{
		//�ݽ������ӽڵ������
		current = current->next;
		count++;
		//�Ƚ�
		if (_compareFunc(compareItem, current->itemExample))
		{
			return count;
		}
	}
	//�����ڷ���0
	return 0;
}

int _compareFunc(item comItem1, item comItem2)
{
	if (!strcmp(comItem1.itemNames, comItem2.itemNames) && !strcmp(comItem1.itemModel, comItem2.itemModel))
	{
		return 1;
	}
	return 0;
}

item fshowNoItem(pItemNode head, int noOfItem)
{
	//���Ŀ���Ƿ����
	if (_checkIsNode(head, noOfItem))
	{
		return _checkIsNode(head, noOfItem)->itemExample;
	}
	//������
	return head->itemExample;
}

int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple))
{
	pItemNode pCurrentNode = head;
	while (pCurrentNode->next != NULL)
	{
		pCurrentNode = pCurrentNode->next;
		if ((*impleFunc)(pCurrentNode->itemExample))
			//������õĺ�������0 ���ж�ִ��
		{
			break;
		}
	}
	return 1;
}

int freverseLinkedList(pItemNode head)
{
	pItemNode ptempHeadNode;
	ptempHeadNode = head->next;
	if (ptempHeadNode == NULL)
	{
		return 0;
	}
	else
	{
		while (_IsBottomForReverse(ptempHeadNode))
		{
			head->next = _IsBottomForReverse(ptempHeadNode)->next;
			_IsBottomForReverse(ptempHeadNode)->next = NULL;
			head = head->next;
		}
		//���һ���ڵ�
		head->next = ptempHeadNode;
	}
	return 0;
}

//�����ڲ�����
pItemNode _setupNewItem(void)
{
	pItemNode newNode = (pItemNode)malloc(sizeof(itemNode));
	//��������Ϊ��
	memset(newNode->itemExample.itemNames, 0, sizeof(newNode->itemExample.itemNames));
	memset(newNode->itemExample.itemModel, 0, sizeof(newNode->itemExample.itemModel));
	newNode->itemExample.itemNumber = 0;
	newNode->next = NULL;

	return newNode;
}

pItemNode _getInfo2Node(pItemNode targetNode, int inputState, item *baseItem)
{
	if (inputState == 0)
	{
		printf("Please Enter the name of item(%d or less):", CHARLENGTH);
		fgets(targetNode->itemExample.itemNames, CHARLENGTH - 1, stdin);
		printf("\nPlease Enter the model of item(%d or less):", CHARLENGTH);
		fgets(targetNode->itemExample.itemModel, CHARLENGTH - 1, stdin);
		printf("\nPlease Enter the count of item:");
		fscanf(stdin, "%d", &targetNode->itemExample.itemNumber);
		printf("\n");	//��������Ư����-��
		while (getchar() != '\n');
		//ȥ�����з�
		targetNode->itemExample.itemNames[strlen(targetNode->itemExample.itemNames) - 1] = '\0';
		targetNode->itemExample.itemModel[strlen(targetNode->itemExample.itemModel) - 1] = '\0';
		return targetNode;
	}
	else
	{
		strcpy(targetNode->itemExample.itemNames, baseItem->itemNames);
		strcpy(targetNode->itemExample.itemModel, baseItem->itemModel);
		targetNode->itemExample.itemNumber = baseItem->itemNumber;
		return targetNode;
	}
}

pItemNode _checkIsNode(pItemNode head, int num2check)
{
	pItemNode pCurrentNode = head;
	for (int count = 1; (num2check == 0 && pCurrentNode->next != NULL)
		|| (count < num2check && pCurrentNode->next != NULL); count++)
	{
		pCurrentNode = pCurrentNode->next;
	}
	switch (num2check)
	{
	case 0:
		return pCurrentNode;
	default:
		return pCurrentNode->next;
		break;
	}
}

pItemNode _IsBottomForReverse(pItemNode head)
{
	pItemNode pCurrentNode;
	pCurrentNode = head;
	if (pCurrentNode->next == NULL)
	{
		return NULL;
	}
	while (pCurrentNode->next->next != NULL)
	{
		pCurrentNode = pCurrentNode->next;
	}
	return pCurrentNode;
}