#include <stdio.h>

int main()
{
    int a,b,c,d;
    int hcf(int a,int b);
    int lcd(int a,int b);
    printf("��������Ҫ�Ƚϵ�����,���ÿո����\n");
    scanf("%d %d",&a,&b);
    c=hcf(a,b);
    d=lcd(a,b);
    printf("�������Ϊ %d\n",c);
    printf("��С������Ϊ %d\n",d);
    return 0;
}

int hcf(int a,int b)
{
    int z,i,h;
    if(a<=b)
    {
        z=a;
    }
    else
    {
        z=b;
    }
    for(i=z;i>0;i--)
    {
        if((a%i==0)&&(b%i==0))
        {
            h=i;
            break;
        }
    }
    return(h);
}

int lcd(int a,int b)
{
    int m,j,l;
    if(a>=b)
    {
        m=a;
    }
    else
    {
        m=b;
    }
    for(j=m;j<=a*b;j++)
    {
        if((j%a==0)&&(j%b==0))
        {
            l=j;
            break;
        }
    }
    return(l);
}
