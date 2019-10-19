#include <stdio.h>
#include <string.h>

int main()
{
    char a[99],b[999];
    int i,j,c[99]={0};
    printf("请输入要统计的字符（可包含空格）：\n");
    gets(a);
    printf("请输入被查找的字符串：\n");
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
    printf("Output:\n查找结果：");
    for(i=0;i<strlen(a);i++)
    {
            printf("\n%c %d",a[i],c[i]);
    }
    return 0;
}
