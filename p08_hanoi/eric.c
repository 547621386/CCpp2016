//Eric 2016-03-05
//p08_hanoi
//�������� ����Ϊ a b c
#include <stdio.h>
//���ڼ�����һ������
#define TOTAL 'a' + 'b' + 'c'

void move(char base, char destination, int level);

int main(void)
{
	int numLevel;
	printf("���������");
	scanf("%d", &numLevel);
	move('a', 'c', numLevel);

	return 0;
}
void move(char base, char destination, int level)
{
	if (level == 1)
	{
		printf("%c2%c\n", base, destination);
	}
	else
	{
		move(base, TOTAL - base - destination, level - 1);
		printf("%c2%c\n", base, destination);
		move(TOTAL - base - destination, destination, level - 1);
	}
}