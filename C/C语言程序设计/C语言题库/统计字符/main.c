#include <stdio.h>
#include <string.h>

int main()
{
    char a[99],b[999];
    int i,j,c[99]={0};
    printf("������Ҫͳ�Ƶ��ַ����ɰ����ո񣩣�\n");
    gets(a);
    printf("�����뱻���ҵ��ַ�����\n");
    gets(b);
    for(i=0;i<strlen(a);i++)
    {
            for(j=0;j<strlen(b);j++)
        {
            if(a[i]==b[j])
            {
                c[i]=c[i]+1;
            }
        }
    }
    printf("Output:\n���ҽ����");
    for(i=0;i<strlen(a);i++)
    {
            printf("\n%c %d",a[i],c[i]);
    }
    return 0;
}
