#include <stdio.h>

int main()
{
    int words1=0,Word1=0,space1=0,number1=0,others1=-1;
    int words2=0,Word2=0,space2=0,number2=0,others2=-1;
    int words3=0,Word3=0,space3=0,number3=0,others3=-1;
    char inter1,inter2,inter3;
    printf("�����������ַ���\n");
    for(;inter1!='\n';)
    {
        scanf("%c",&inter1);
        if('a'<=inter1&&inter1<='z')
        words1++;
        else if('A'<=inter1&&inter1<='Z')
        Word1++;
        else if(inter1==' ')
        space1++;
        else if('0'<=inter1&&inter1<='9')
        number1++;
        else
        others1++;
        if(inter1=='\n')
            {break;
    }
    }
    for(;inter2!='\n';)
    {
        scanf("%c",&inter2);
        if('a'<=inter2&&inter2<='z')
        words2++;
        else if('A'<=inter2&&inter2<='Z')
        Word2++;
        else if(inter2==' ')
        space2++;
        else if('0'<=inter2&&inter2<='9')
        number2++;
        else
        others2++;
        if(inter2=='\n')
            {break;
    }
    }
    for(;inter3!='\n';)
    {
        scanf("%c",&inter3);
        if('a'<=inter3&&inter3<='z')
        words3++;
        else if('A'<=inter3&&inter3<='Z')
        Word3++;
        else if(inter3==' ')
        space3++;
        else if('0'<=inter3&&inter3<='9')
        number3++;
        else
        others3++;
        if(inter3=='\n')
            {break;
    }
    }
    printf("СдӢ����ĸ��%d��\n��дӢ����ĸ%d��\n�ո�%d��\n����%d��\n�����ַ�%d��\n",words1+words2+words3,Word1+Word2+Word3,space1+space2+space3,number1+number2+number3,others1+others2+others3);
    return 0;
}
