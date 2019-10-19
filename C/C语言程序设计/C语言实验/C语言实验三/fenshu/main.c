#include <stdio.h>

int main()
{
    int a[10][5],b[5],c[10];
    int i,j;
    printf("请输入成绩：\n");
    printf("科目    一 二 三 四 五\n");
    for(j=1;j<=10;j++)//输入成绩
    {
        printf("学生%d   ",j);
        scanf("%d %d %d %d %d",&a[j][1],&a[j][2],&a[j][3],&a[j][4],&a[j][5]);
    }
    printf("\n学生成绩平均分：\n");//学生成绩平均分
    for(j=1;j<=10;j++)
    {
       c[j]=0.2*(a[j][1]+a[j][2]+a[j][3]+a[j][4]+a[j][5]);
       printf("学生%d成绩平均分：%d\n",j,c[j]);
    }
    printf("\n学科成绩平均分：\n");//学科成绩平均分
    for(i=1;i<=5;i++)
    {
    b[i]=0.1*(a[1][i]+a[2][i]+a[3][i]+a[4][i]+a[5][i]+a[6][i]+a[7][i]+a[8][i]+a[9][i]+a[10][i]);
    printf("学科%d成绩平均分：%d\n",i,b[i]);
    }
    //所有分数最高分
    int max;
    max=a[1][1];
    for(j=1;j<=10;j++)//找出最高分及其j,i值,并判断有几个最大值
    {
        for(i=1;i<=5;i++)
        {
        if(a[j][i]>=max)
        {
            max=a[j][i];
        }
        }
    }
    printf("\n所有分数最高分为:%d\n分别为:\n",max);
    for(j=1;j<=10;j++)//找出所有最高分及其j,i值
    {
        for(i=1;i<=5;i++)
        {
        if(a[j][i]==max)
        {
            printf("学生%d科目%d\n",j,i);
        }
        }
    }
    return 0;
}
