#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("ÇëÊäÈë×Ö·û´®£º\n");
    for(;a!='\n';)
    {
        scanf("%c",&a);
        if(a=='\n') break;
        else
        {
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
        {
            printf("%c",a);
        }
        }
    }
    return 0;
}
