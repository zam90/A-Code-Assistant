#include <stdio.h>

int main()
{
    int n, la, kao, yin, i, mini, t;
    char s[101];
	printf("请输入现在队伍的列数:\n");
	scanf("%d", &n);
	printf("拉面的制作时间:\n");
	scanf("%d", &la);
    printf("烤肉的制作时间:\n");
	scanf("%d", &kao);
	printf("饮料的制作时间:\n");
	scanf("%d",&yin);
    mini = 100*3*(la+kao+yin);
    while (n--)
	 {
        printf("第%d对的排列情况:\n",n+1);
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
	printf("\nOutput:\n最快吃上饭的那个队伍的排队时间:%d\n", mini);
        return 0;
}
