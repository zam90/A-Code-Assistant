#include <stdio.h>

int main()
{
    int m,k,day=1,i,j=0;
    printf("Please input m,k:\n");
    scanf("%d %d",&m,&k);
    printf("Output:\n");
    for(i=1;;i++)
    {
        if(j==k)
        {
            m=m+1;j=0;
        }
        m=m-1;
        day++;j++;
        if(m==0)
        {
            break;
        }
    }
    printf("The day is:%d\n",day);
    for(i=0;;i++)
    {
        scanf("%d %d",&m,&k);
        day=1;j=0;
        if(m==0&&k==0)
        {
            break;
        }
        else
        {
        for(i=1;;i++)
    {
        if(j==k)
        {
            m=m+1;j=0;
        }
        m=m-1;
        day++;j++;
        if(m==0)
        {
            break;
        }
    }
    printf("The day is:%d\n",day);
        }
    }
    return 0;
}
