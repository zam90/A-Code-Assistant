#include <stdio.h>

int main()
{
    int i,x,t,a,b,c,m;
    printf("Please input test times: ");
    scanf("%d",&t);
    printf("Output:");
    for(i=1;i<=t;i++)
    {
        m=0;
        printf("\nEnter a b c:\n");
        scanf("%d %d %d",&a,&b,&c);
        for(x=1000;x<=9999;x++)
        {
            if((x%a==0)&&((x+1)%b==0)&&((x+2)%c==0))
            {m++;break;}
        }
        if(m==1)
        {
            printf("The ans is: %d",x);
        }
        else
        printf("The ans is: Impossible");
    }
    return 0;
}
