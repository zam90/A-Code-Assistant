#include <stdlib.h>

int cmp(const void *p, const void *q);
int main(int argc, char const *argv[]) {
  /* code */
  int i;
  int a[6];
  int tmp,sum=0;
  int *p;
  printf("please input a:");
  for ( i = 0; i < 6; i++) {
    /* code */
    scanf("%d",&a[i] );
  }
  tmp=a[0];
  qsort(a,sizeof(a)/sizeof(a[0]),sizeof(int),cmp);
  p=(int *)bsearch(&tmp,a,sizeof(a)/sizeof(a[0]),sizeof(int),cmp);
  for ( i = 0; i < (p-&a[0]); i++) {
    /* code */
    sum+=a[i];
  }
  printf("Output:\n");
  printf("%d", sum);
  return 0;
}
int cmp(const void *p, const void *q)
{
    return (*(int *)p - *(int *)q);
}
