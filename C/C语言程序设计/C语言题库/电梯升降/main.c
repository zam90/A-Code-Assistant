#include <stdio.h>

int main()
{
    int i=1,t=0,num,l;int n[101];
    n[0]=0;
    for(;;)
    {
        i=1;
        t=0;
        while(1)
    {
        scanf("%d",&num);
        char c=getchar();
        n[i++]=num;
        if(c=='\n')
        {
            break;
        }
   }
   l=i-1;
       if(n[1]!=0)
    {
        for(i=0;i<l;i++)
    {
        if(n[i]>=n[i+1])
        {
            t=t+4*(n[i]-n[i+1]);
        }
        else
        {
            t=t+6*(n[i+1]-n[i]);
        }
    }
    printf("Output:\n%d\n",t+5);
    }
    else
    {
        break;break;
    }
    }
    return 0;
}
