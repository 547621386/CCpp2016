#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int i,n,j,k,m=1;                            //k��������Ƿ�������m������ʾ�������������һ����±�
    int a[500]={2,3};                           //aΪ��������
    printf("2\t3\t");
    for(i=5;i<1000;i+=2){
        k=0;                                    //��ѭ����ʼʱ�ñ����Ϊ0����ʾ��δ���ֿɱ�����
        n=(int)sqrt(i);
        for(j=0;a[j]!=0&&a[j]<=n;j++){
            if(i%a[j]==0){
                k=1;                            //���������ӣ��ñ��Ϊ1������ѭ��
                break;
            }
        }
        if(k==0){                                //���Ϊ0��ʾδ���������ӣ�Ϊ��������ӡ�����������������
            m+=1;
            a[m]=i;
            printf("%d\t",i);
        }
    }
    printf("\nThe time taken:%fs",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
