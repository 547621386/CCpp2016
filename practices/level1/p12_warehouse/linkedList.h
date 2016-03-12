//Eric Linkedlist
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#define CHARLENGTH 41
typedef struct {
	char itemNames[CHARLENGTH];
	char itemModel[CHARLENGTH];
	int itemNumber;
} item;

typedef struct itemnode {
	item itemExample;
	struct itemnode *next;
}itemNode;

typedef itemNode * pItemNode;

//��ʼ���б� ����ͷָ�� ʧ�ܷ���NULL
pItemNode finitialize(void);
//��ָ��λ�ò���һ���ڵ� 0Ϊĩβ return 1 when succeed insert
//inputState 0 ��׼���� 1 ��baseItem����
int finsertNode(pItemNode head, int num2insert, int inputState, item *baseItem);
//ɾ��ָ���ڵ� return 1 when succeed delete
int fdeleteNode(pItemNode head, int num2delete);
//������ͬ�Ľڵ� ���ؽڵ���� �����ڷ���0
int ffindNode(pItemNode head, item compareItem);
//�ȽϺ��� 1 Ϊ���
int _compareFunc(item comItem1, item comItem2);
//�����ض��ڵ��Item ����0������ͷItem
item fshowNoItem(pItemNode head, int noOfItem);
//��ÿ���ڵ�Ӧ�ú��� ��Ӧ�ú�������0���ִ�� return 1 when succeed
int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple));
//��ת����
int freverseLinkedList(pItemNode head);
//�����սڵ�����ֵ��Ϊ0��/0 �ɹ����ص�ַ ʧ�ܷ���NULL
pItemNode _setupNewItem(void);
//��ȡ��Ϣд��ڵ� inputState = 0 ��׼������� 1 ���ƽṹ�������setup a new Node return NULL when fail
pItemNode _getInfo2Node(pItemNode targetNode, int inputState, item *baseItem);
//���ڵ��Ƿ���� num2check = 0 ����β���ڵ�ĵ�ַ
//return pointer when the item exist, return NULL when unexist
pItemNode _checkIsNode(pItemNode head, int num2check);
//����β���ڵ�ǰһ���ڵ��λ��
pItemNode _IsBottomForReverse(pItemNode head);

#endif