#include <stdio.h>

int main()
{
    int words=0,space=0,number=0,others=-1;
    char inter;
    printf("������һ���ַ�\n");
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
    printf("Ӣ����ĸ��%d��\n�ո�%d��\n����%d��\n�����ַ�%d��\n",words,space,number,others);
    return 0;
}
