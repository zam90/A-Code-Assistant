#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("color F0");
    int a=1,b=2,c=3,m,n;
    m=(!--a)||((a=2)&&(b=3)&&(c=4))||(n=5);
    m=(a++>--b)||!--a&&(a==0)&&(b=1)&&(c=4)||(n=5);
    printf("%d %d %d %d %d",a,b,c,m,n);
    return 0;
}
