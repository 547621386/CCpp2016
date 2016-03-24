#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
char map[12][12]=
{
    '#','#','#','#','#','#','#','#','#','#','#','#',
    '#','@',' ',' ',' ',' ',' ',' ','#','#','#','#',
    '#','#',' ','#','#','#','#',' ','#','#','#','#',
    '#','#',' ','#','#','#','#','#','#','#','#','#',
    '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#',
    '#',' ','#','#',' ','#',' ','#','#',' ','#','#',
    '#',' ',' ','#',' ','#',' ','#','#',' ','#','#',
    '#','#',' ','#',' ','#',' ','#','#',' ','#','#',
    '#','#',' ',' ',' ','#',' ','#','#',' ',' ','#',
    '#','#','#','#','#','#',' ','#','#','#',' ','#',
    '#','#','#','#','#','#','#','#','#','#',' ',' ',
    '#','#','#','#','#','#','#','#','#','#','#','#'
};
int ynum=1;
int xnum=1;
//�˵�λ��
void ShowMap(void);
//��ʾ��ͼ
void Judge(int ymove,int xmove);
//�ж������Ӱ��
void Move(void);
//�����ƶ�
void GameStart(void);
//��Ϸ��ʼ
int main()
{
    GameStart();
    return 0;
}
void GameStart(void)
{
    for (;;)
    {
        system("cls");
        printf("WSAD����@����������ƶ������ڴ���ʤ��\n");
        ShowMap();
        Move();
        if ((ynum==10)&&(xnum==11))
        {
            system("cls");
            printf("WSAD����@����������ƶ������ڴ���ʤ��\n");
            ShowMap();
            break;
        }
    }
    system("pause");
    system("cls");
    printf("congratulations!");
}
void ShowMap(void)
{
    for (int i=0;i<=11;i++)
    {
        for (int j=0;j<=11;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
void Move(void)
{
    char direction;
    direction=getch();
    switch (direction)
    {
        case 'w':
        case 'W':Judge(-1,0);
                 break;
        case 's':
        case 'S':Judge(1,0);
                 break;
        case 'a':
        case 'A':Judge(0,-1);
                 break;
        case 'd':
        case 'D':Judge(0,1);
                 break;
    }
}
void Judge(int ymove,int xmove)
{
    if (' '==map[ynum+ymove][xnum+xmove])
    {
        map[ynum+ymove][xnum+xmove]='@';
        map[ynum][xnum]=' ';
        ynum=ynum+ymove;
        xnum=xnum+xmove;
    }
}
