#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[8]={'1','w','+','2','p','*','e','4'};
    printf(s);
    printf("\n");
    int n = 0;	//É¾³ý×Ö·û¼ÆÊýÆ÷
	for (int i = 0; i < 8-n; i++) {
		if (!((s[i] > '0' || s[i] == '0') && (s[i] < '9' || s[i] == '9') || (s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == '(') || (s[i] == ')' || (s[i] == '.')))) {
			int m=8-i-1-n;
			int o=i;
			int j=0;
			for (j;j<=m;j++)
			{
				s[o] = s[o+1] ;
				o++;
			}
			n++;
		}
	}
	printf(s);
    return 0;
}
