#include<stdio.h>
#include<string.h>

char tw[4][15]={"bowl","knife","fork","chopsticks"};

int main()
{
        int n,i,j,c;
        char s[200][15];
		printf("Please input box number: ");
		scanf("%d",&n);
		printf("Input names:\n");
		for(i=0;i<n;i++)
             scanf("%s",s[i]);
		printf("Output:\n");

        c=0;

        for(j=0;j<n;j++)
        {
			for(i=0;i<4;i++)
            if(strcmp(s[j],tw[i])==0)
            {
                  c++;
                  if(c==1)
					printf("[%s]",s[j]);
                  else
                     printf(" [%s]",s[j]);
                  break;
             }
        }
       printf("\n");

       return 0;
}
