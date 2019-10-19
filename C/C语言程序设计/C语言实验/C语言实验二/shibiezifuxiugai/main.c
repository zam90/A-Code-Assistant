#include <stdio.h>

int main()
{
    int words=0,Word=0,space=0,number=0,others=-1;
    char inter;
    printf("请输入一串字符\n");
    for(;inter!='\n';)
    {
        scanf("%c",&inter);
        if('a'<=inter&&inter<='z')
        words++;
        else if('A'<=inter&&inter<='Z')
        Word++;
        else if(inter==' ')
        space++;
        else if('0'<=inter&&inter<='9')
        number++;
        else
        others++;
    }
    printf("小写英文字母共%d个\n大写英文字母%d个\n空格%d个\n数字%d个\n其他字符%d个\n",words,Word,space,number,others);
    return 0;
}
