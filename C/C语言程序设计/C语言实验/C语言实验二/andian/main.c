#include<stdio.h>

int main()
{
    int a[20][20],b,c=0,d,m,n,i,j;        //b������ǣ�c����������d�������ѭ������
    printf("��������������\n");
    scanf("%d",&m);
    printf("��������������\n");
    scanf("%d",&n);
    printf("������һ��%d��%d�Ķ�ά����\n",m,n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);        //��������
        for(i=0;i<m;i++)                //��ѭ��
            for(j=0;j<n;j++)            //��ѭ��
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
        if(c==0)printf("������û�а���\n");
        else printf("�����鹲%d������\n",c);
    return 0;
 }
