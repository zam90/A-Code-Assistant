#include <stdio.h>
#include <string.h>

int main()
{
    char a[21];
    int l,i,j,c=0;
    printf("Input the string: ");
    gets(a);
    l=strlen(a);
    if(l%2==0)
    {
        j=(l/2);
        i=(l/2)-1;
        printf("Output:\n");
        for(;i>=0;)
        {
            if(a[i]==a[j])
            {
                c++;
            }
            i--;j++;
        }
        if(c==l/2)
        {
            printf("是回文串!");
        }
        else
        {
            printf("不是回文串!");
        }
    }
    else
    {
        j=((l+1)/2);
        i=((l+1)/2)-2;
        printf("Output:\n");
        for(;i>=0;)
        {
            if(a[i]==a[j])
            {
                c++;
            }
            i--;j++;
        }
        if(c==(l-1)/2)
        {
            printf("是回文串！");
        }
        else
        {
            printf("不是回文串！");
        }
    }
    return 0;
}
