#include<stdio.h>

int main()
{
    int a[20][20],b,c=0,d,m,n,i,j;        //b用来标记，c用来计数，d是另外的循环控制
    printf("请输入数组行数\n");
    scanf("%d",&m);
    printf("请输入数组列数\n");
    scanf("%d",&n);
    printf("请输入一个%d×%d的二维数组\n",m,n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);        //输入数组
        for(i=0;i<m;i++)                //行循环
            for(j=0;j<n;j++)            //列循环
            {
            b=1;
            for(d=0;d<n;d++)        //判断是否行上最大
                if(a[i][j]<a[i][d]) b=0;
                if(b==0) continue;
                for(d=0;d<m;d++)        //判断是否列上最小
                if(a[i][j]>a[d][j]) b=0;
                if(b==0) continue;
                c++;
                printf("第%d个鞍点：a[%d][%d]\n",c,a[i][j],i+1,j+1);
            }
        if(c==0)printf("该数组没有鞍点\n");
        else printf("该数组共%d个鞍点\n",c);
    return 0;
 }
