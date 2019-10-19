#include<stdio.h>
int main()
{
    int a[11]={0,10,20,30,40,50,60,70,80,90};
    int b,i=0,j=0;
    printf("排好顺序的数组为0,10,20,30,40,50,60,70,80,90\n");
    printf("请输入需要插入的数字：");
    scanf("%d",&b);
    for(i=9;i>=0;i--)
       if(b<a[i])
            a[i+1]=a[i];

        else
            {
             a[i+1]=b;
             break;
            }
    for(i=0;i<11;i++)
        printf("%d ",a[i]);
    system("pause");
    return 0;
}
