#include <stdio.h>

int main()
{
    int b,s,g;
    for(b=0;b<9;b++)
    for(s=0;s<9;s++)
    for(g=0;g<9;g++)
    if(b*100+s*10+g==b*b*b+s*s*s+g*g*g && b*100+s*10+g>100)
    printf("%d\n",b*100+s*10+g);

    return 0;
}

