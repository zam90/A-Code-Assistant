#include <stdio.h>
#include <stdlib.h>

int main()
{
    //声明函数
    int huzhi(int a,int b);
    int jio(int a,int b);
    int tiaojian(int a,int b);
    int gongshi(int a,int b,int v,int n);
    //设置变量
    int a=2,b=1,v=1,n=0;
    int t=0;//求解标记，成功求解标记为1
    int s=2048;//求解精度，即a,b,v的取值上限
    printf("请输入需要验证是否为同余数的数字n：");
    scanf("%d",&n);
    //在限定范围内循环枚举尝试求解
    for(a=2;a<=s;a++)
    {
        for(b=1;b<a;b++)
        {
            for(v=1;v<=s;v++)
            {
                //判断是否满足四个条件
                if(huzhi(a,b)&&jio(a,b)&&tiaojian(a,b)&&gongshi(a,b,v,n))
                {
                    printf("n=%d是同余数\n",n);
                    printf("公式中a=%d,b=%d,v=%d\n",a,b,v);
                    t=1;
                    break;
                }
            }
            //若已求解成功则跳出循环
            if(t==1)
            {
                break;
            }
        }
        //若已求解成功则跳出循环
        if(t==1)
        {
            break;
        }
    }
    //若在精度内未找到解则提示
    if(t==0)
    {
        printf("n=%d在该精度内不是同余数",n);
    }
    return 0;
}

//条件一：a,b互质
//若互质返回1,不互质返回0
int huzhi(int a,int b){
    int t;
    if(a<b)
    {
        t=a;a=b;b=t;
    }
    while(a%b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    if(b==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//条件二：a,b一奇数一偶数
//满足条件返回1，不满足条件返回0
int jio(int a,int b){
    if((a%2==0&&b%2!=0)||(a%2!=0&&b%2==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//条件三：a,b正整数并且a>b
//满足条件返回1，不满足条件返回0
int tiaojian(int a,int b){
    if(a>0&&b>0&&a>b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//条件四：满足判断公式
//满足公式返回1，不满足公式返回0
int gongshi(int a,int b,int v,int n){
    int left=n*v*v,right1=4*a*b*(a*a-b*b),right2=6*a*a*b*b-a*a*a*a-b*b*b*b,right3=-6*a*a*b*b+a*a*a*a+b*b*b*b;
    if(left==right1||left==right2||left==right3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
