#include <stdio.h>
#include <stdlib.h>
#define keyNum 6
#define isMajuscule(c) c<='Z'&&c>='A'
#define tempCharacter(c) c<='Z'?c-'A':c-'a'
char encrypt(char);
char decrypt(char);
int main()
{
    int command=0;
    puts("1.����");
    puts("2.����");
    while (command!='1'&&command!='2')
    {
        puts("������1����2���в���");
        command=getchar();
    }
    char(*whatWantToDo)(char character);
    puts("����������Ҫ���ܵ����ݰ�");
    if(command=='1')
    {
        whatWantToDo=encrypt;
    }
    else
    {
        whatWantToDo=decrypt;
    }
    char ch=0;
    getchar();
    while ((ch=getchar())!='\n')
    {
        ch=whatWantToDo(ch);
        putchar(ch);
    }
}

char encrypt(char character)
{
    char temp=tempCharacter(character);
    if(isMajuscule(character))
    {
        return (temp+keyNum)%26+'A';
    }
    else
    {
        return  (temp+keyNum)%26+'a';
    }
}
char decrypt(char character)
{
    char temp=tempCharacter(character);
    if(isMajuscule(character))
    {
        return (temp+26-keyNum)%26+'A';
    }
    else
    {
        return (temp+26-keyNum)%26+'a';
    }
}
