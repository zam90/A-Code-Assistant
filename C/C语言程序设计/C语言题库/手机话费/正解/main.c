#include<stdio.h>

int main()
{
 int m,k,d;
 printf("Please input m,k:\n");
 scanf("%d%d",&m,&k);
 printf("Output:\n");
 while(m||k)
 {

 d=0;
 while(m)
 {
 m--;
 d++;
 if(d%k==0)
 m++;
 }
 printf("The day is:%d\n",d);
 scanf("%d%d",&m,&k);
 }
 return 0;
}
