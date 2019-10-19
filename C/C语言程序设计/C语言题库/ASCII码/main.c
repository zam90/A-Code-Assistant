#include <stdio.h>

int main()
{
    int t;
    printf("Please input t:\n");
    scanf("%d",&t);
    int num,i,a[t];
    for(i=0;i<t;i++)
    {
        scanf("%d",&num);
        char c=getchar();
        a[i]=num;
    }
    printf("Output:\n");
    for(i=0;i<t;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}
