#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[999];
    int i,num=0;
    printf("������һ�����ӣ�\n");
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
        {
            num++;
        }
    }
    printf("�ܵ�������%d\n",num+1);
    printf("���ʷֱ�Ϊ��\n");
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==' '||a[i]==','||a[i]==':'||a[i]=='.'||a[i]=='?'||a[i]=='!')
        {
            printf("\n");
            continue;
        }
        printf("%c",a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
