#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void input();
void output();
void print();
void menu();
void end();
int m,n;
int main()
{
    FILE *fpt;
    fpt = fopen("d:\\house.txt","r+");
    fscanf(fpt,"%d\n",&m);
    fscanf(fpt,"%d\n",&n);
    fclose(fpt);
    menu();
    return 0;
}
void print(){

    system("cls");
    printf("����б�\n");
    printf("��Ʒa %d \t ��Ʒb %d\n",m,n);
    printf("�����������");
    getch();

}
void input(){
    int a,b;
    system("cls");
    printf("������Ʒ��\n");
    printf("��Ʒa: ");
    scanf("%d",&a);
    m=m+a;
    printf("��Ʒb: ");
    scanf("%d",&b);
    n=n+b;
    printf("�����������");
    getch();

}
void output(){
    int i,j;
    system("cls");
    printf("�����Ʒ\n");
    printf("�����Ʒa: ");
    scanf("%d",&i);
    m=n-i;
    printf("�������b: ");
    scanf("%d",&j);
    n=n-j;
    printf("�����������");
    getch();
}
void menu(){
    int key;



        while(1){
            system("cls");
            printf("��Ʒ�嵥\n");
            printf("�����ſ�ʼ����\n");
            printf("1.��ʾ�б�\n2.������Ʒ\n3.�����Ʒ\n4.�˳�ϵͳ\n");
            scanf("%d",&key);
            switch(key){
                 case 1:
                        print();
                        break;
                 case 2:
                        input();
                        break;
                 case 3:
                        output();
                        break;
                 case 4:
                        end();
                 default: break;
    }

        }




}
void end(){
    FILE *fpt;
    fpt = fopen("d:\\house.txt","w+");//���ĵ���д��
    fprintf(fpt,"%d\n",m);
    fprintf(fpt,"%d",n);
    fclose(fpt);
    exit(0);
}
