#include <stdio.h>

int main()
{
    int n, la, kao, yin, i, mini, t;
    char s[101];
	printf("���������ڶ��������:\n");
	scanf("%d", &n);
	printf("���������ʱ��:\n");
	scanf("%d", &la);
    printf("���������ʱ��:\n");
	scanf("%d", &kao);
	printf("���ϵ�����ʱ��:\n");
	scanf("%d",&yin);
    mini = 100*3*(la+kao+yin);
    while (n--)
	 {
        printf("��%d�Ե��������:\n",n+1);
            scanf("%s", s);
            printf("%s\n",s);
            for (t = i = 0; s[i]; i++)
	     {
                   if (s[i] == 'A'||s[i] == 'a')
                             t += la + kao + yin;
                   else if (s[i] == 'B'||s[i] == 'b')
                             t += la * 2 + kao;
                   else
                             t += la * 3 + kao * 3 + yin * 2;
             }
             if (t < mini)
                                mini = t;
          }
	printf("\nOutput:\n�����Ϸ����Ǹ�������Ŷ�ʱ��:%d\n", mini);
        return 0;
}
