#include <stdio.h>


int main()
{
    int n;
    int i;
    double h=100,H=0;
    printf("Please input n: ");
    scanf("%d",&n);
    printf("\nOutput:\n");
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            h=h/2;
            if(i>=n-1)
                break;
            H=H+h*2;
        }
        printf("�ܹ�����ĸ߶�Ϊ(��):%.3lf.\n",H+100);
        printf("��%d�ε���ĸ߶�Ϊ:%.3lf.",n,h);
    }
    else
    {
      printf("Input error!");
    }
    return 0;
}
