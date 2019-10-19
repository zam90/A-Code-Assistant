#include <stdio.h>

int main()
{
    int n,i;
    printf("Please enter number: ");
    scanf("%d",&n);
    printf("Output:\n");
    if(n>0&&n<=200)
    {
        for(i=1;;i++)
        {
            if(n==1)
            {
                break;
            }
            else if(n%2==0)
            {
                n=n/2;
                printf("[%d]: %d/2=%d\n",i,2*n,n);
            }
            else if(n%2!=0)
            {
                n=3*n+1;
                printf("[%d]: %d*3+1=%d\n",i,(n-1)/3,n);
            }
        }
    }
    else
    {
        printf("Input error!");
    }
    return 0;
}
