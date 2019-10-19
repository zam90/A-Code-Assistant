#include <stdio.h>
int main()
{
  /******start******/
    int a,b;
    int *pointer_1,*pointer_2;
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    pointer_1=&a;
    pointer_2=&b;
/******end******/
  printf("Output:\n");
  printf("*pointer_1=%d,*pointer_2=%d\n",*pointer_1,*pointer_2);
  return 0;
}
