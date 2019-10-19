#include <stdio.h>

int main()
{
    char p[1000];
    int lenstr(const char* str);
    printf("ÇëÊäÈë×Ö·û´®:");
    gets(p);
    printf("×Ö·û´®³¤¶ÈÎª:%d\n",lenstr(p));
    return 0;
}

int lenstr(const char* str)
{
    int i = -1;
    while (str[++i]);
    return i;
}
