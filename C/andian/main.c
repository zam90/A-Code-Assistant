#include<stdio.h>

int main()
{
    int a[m][n],i,j,b,c=0,d,m,n;        //b������ǣ�c����������d�������ѭ������
    printf("��������������������3*4\n");
    scanf("%d*%d",&m,&n);
    printf("������һ��%d��%d�Ķ�ά����\n",m,n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);        //��������
        for(i=0;i<m;i++)                //��һ��ѭ����������
            for(j=0;j<n;j++)            //�ڶ���ѭ����������
            {
            b=1;
            for(d=0;d<n;d++)        //�ж��Ƿ��������
                if(a[i][j]<a[i][d]) b=0;
                if(b==0) continue;
                for(d=0;d<m;d++)        //�ж��Ƿ�������С
                if(a[i][j]>a[d][j]) b=0;
                if(b==0) continue;
                c++;
                printf("��%d�����㣺a[%d][%d]\n",c,a[i][j],i+1,j+1);
            }
        if(c==0)printf("������û�а���");
        else printf("��������%d������",c);
    return 0;
 }
