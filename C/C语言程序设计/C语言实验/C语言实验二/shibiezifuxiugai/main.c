#include <stdio.h>

int main()
{
    int words=0,Word=0,space=0,number=0,others=-1;
    char inter;
    printf("������һ���ַ�\n");
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
    printf("СдӢ����ĸ��%d��\n��дӢ����ĸ%d��\n�ո�%d��\n����%d��\n�����ַ�%d��\n",words,Word,space,number,others);
    return 0;
}
