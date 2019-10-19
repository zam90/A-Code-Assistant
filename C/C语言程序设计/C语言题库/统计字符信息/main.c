#include <stdio.h>

int main()
{
    int i,cha=0,space=0,digit=0,others=0;char inter;
    printf("Input:\nPlease input some characters\n");
    for(i=1;;i++)
    {
        scanf("%c",&inter);
        if(inter=='\n') break;
        else if((inter>='a'&&inter<='z')||(inter>='A'&&inter<='Z')) cha++;
        else if(inter>='0'&&inter<='9') digit++;
        else if(inter==' ') space++;
        else others++;
    }
    printf("Output:\nall in all:char=%d,space=%d digit=%d others=%d",cha,space,digit,others);
    return 0;
}
