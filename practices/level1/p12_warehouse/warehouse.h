#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H
//������ �������� ����/����/�����¼
void fstartWareHouse(void);
//��鴢���ļ�1���� 0 ������
int _checkIsFileExist(void);
//�����ļ�
int _createRecordFile(void);
//�����ļ�
int _loadRecord(pItemNode head);
//�����ļ�
int _saveRecord(pItemNode head);
//�����ļ�����
int __saveRecordOutput(item toImple);
//չʾ����ѡ��
void _showCommandList(void);
//������������Ӧ���� ����0Ϊ�˳�ϵͳ
int _getCommandAndImplement(pItemNode head);
//��������Ƿ�Ϊ�շ���0Ϊ�� 1�ǿ�
int _checkIsEmpty(pItemNode head);
//���Ӽ�¼ ���
int _addItem(pItemNode head);
int __addItemExist(pItemNode head, pItemNode tempNode);
int __addItemUnexist(pItemNode head, pItemNode tempNode);
//����
int _outItem(pItemNode head);
//������л��Ｐ�ź��Ƿ���� 0 ������ 1 ����
int __checkIsItemRecord(pItemNode head, item toCompare);
//��������Ƿ��㹻 0���� 1 ��
int __outItemNumIsEnough(pItemNode head, item toCheck);
//��ʾ�����¼
int _showItemList(pItemNode head);
//չʾһ�������¼
int __showItem(item toImple);

#endif