#include <stdio.h>

int main()
{
    int a[10][5],b[5],c[10];
    int i,j;
    printf("������ɼ���\n");
    printf("��Ŀ    һ �� �� �� ��\n");
    for(j=1;j<=10;j++)//����ɼ�
    {
        printf("ѧ��%d   ",j);
        scanf("%d %d %d %d %d",&a[j][1],&a[j][2],&a[j][3],&a[j][4],&a[j][5]);
    }
    printf("\nѧ���ɼ�ƽ���֣�\n");//ѧ���ɼ�ƽ����
    for(j=1;j<=10;j++)
    {
       c[j]=0.2*(a[j][1]+a[j][2]+a[j][3]+a[j][4]+a[j][5]);
       printf("ѧ��%d�ɼ�ƽ���֣�%d\n",j,c[j]);
    }
    printf("\nѧ�Ƴɼ�ƽ���֣�\n");//ѧ�Ƴɼ�ƽ����
    for(i=1;i<=5;i++)
    {
    b[i]=0.1*(a[1][i]+a[2][i]+a[3][i]+a[4][i]+a[5][i]+a[6][i]+a[7][i]+a[8][i]+a[9][i]+a[10][i]);
    printf("ѧ��%d�ɼ�ƽ���֣�%d\n",i,b[i]);
    }
    //���з�����߷�
    int max;
    max=a[1][1];
    for(j=1;j<=10;j++)//�ҳ���߷ּ���j,iֵ,���ж��м������ֵ
    {
        for(i=1;i<=5;i++)
        {
        if(a[j][i]>=max)
        {
            max=a[j][i];
        }
        }
    }
    printf("\n���з�����߷�Ϊ:%d\n�ֱ�Ϊ:\n",max);
    for(j=1;j<=10;j++)//�ҳ�������߷ּ���j,iֵ
    {
        for(i=1;i<=5;i++)
        {
        if(a[j][i]==max)
        {
            printf("ѧ��%d��Ŀ%d\n",j,i);
        }
        }
    }
    return 0;
}
