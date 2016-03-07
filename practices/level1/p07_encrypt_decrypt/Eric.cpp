//Eric 2016-03-05
//p07_encrypt_decrypt
//��Ҫ���ܽ��ܵ��ļ�����Ϊin.txt �����out.txt
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fshowGetOrder(void);
char fencrypt(char operatorChar);
char fdecrypt(char operatorChar);
void fstartOpeate(int enDeFlag);	//������
int main(void)
{
	//int enDeFlag;

	//printf("1.Encrypt 2.Decrypt 3.Quit: ");
	//scanf("%d", &enDeFlag);

	fstartOpeate(fshowGetOrder());
	/*//�ض����������
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);
	*/

	/*//while (getchar() != '\n');
	if (enDeFlag == 1)
	{
		encrypt();
	}
	else
	{
		decrypt();
	}*/

	return 0;
}

int fshowGetOrder(void)
{
	int order;
	printf("1.Encrypt 2.Decrypt 3.Quit: ");
	while (scanf("%d", &order) == 1)
	{
		//���봦��
		switch (order)
		{
		case 1:
		case 2:
		case 3:
			return order;
		default:
			printf("Please Enter the number among 1 2 3:");
		}
	}
}
void fstartOpeate(int enDeFlag)
{
	FILE *pointerFileInput;
	char tempInput;
	switch (enDeFlag)
	{
	case 3:
		printf("Done.");
		return;
	case 1:
	case 2:
		pointerFileInput = fopen("in.txt", "r");
		//freopen("in.txt", "r", stdin);
		//�ж�in.txt�Ĵ���
		if (pointerFileInput == NULL)
		{
			printf("Error : File error.");
			return;
		}
		fclose(pointerFileInput);

		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		while ((tempInput = getchar()) != EOF)
		{
			//ѡ����ܽ���
			switch (enDeFlag)
			{
			case 1:
				printf("%c", fencrypt(tempInput));
				break;
			case 2:
				printf("%c", fdecrypt(tempInput));
				break;
			default:
				printf("Error : ed_switch error");
				return;
			}
		}
	}
}

char fencrypt(char operatorChar)
{
	return operatorChar - 1;
}
char fdecrypt(char operatorChar)
{
	return operatorChar + 1;
}
/*void encrypt(void)
{
	char temp;
	int count1 = 1;
	while ((temp = getchar()) != EOF)
	{
		putchar(temp);
		srand(clock());
		for (int count2 = 0; count2 < count1; count2++)
		{
			putchar('a' + rand() % 24);
		}
		srand(count1);
		count1 = rand() % 10 + 1;
	}
}

void decrypt(void)
{
	int count1 = 1;
	char temp;
	while ((temp = getchar()) != EOF)
	{
		putchar(temp);
		for (int count2 = 0; count2 < count1; count2++)
		{
			getchar();
		}
		srand(count1);
		count1 = rand() % 10 + 1;
	}
}*/