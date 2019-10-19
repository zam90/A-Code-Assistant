#include <stdio.h>

int main()
{
    char a;
    void shibie(char inter);
    printf("请输入一串字符\n");
    shibie(a);
    return 0;
}

void shibie(char inter)
{
    int words=0,space=0,number=0,others=-1;
    for(;inter!='\n';)
    {
        scanf("%c",&inter);
        if(('a'<=inter&&inter<='z')||('A'<=inter&&inter<='Z'))
        words++;
        else if(inter==' ')
        space++;
        else if('0'<=inter&&inter<='9')
        number++;
        else
        others++;
    }
    printf("英文字母共%d个\n空格%d个\n数字%d个\n其他字符%d个\n",words,space,number,others);
}
