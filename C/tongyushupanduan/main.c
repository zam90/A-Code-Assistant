#include <stdio.h>
#include <stdlib.h>

int main()
{
    //��������
    int huzhi(int a,int b);
    int jio(int a,int b);
    int tiaojian(int a,int b);
    int gongshi(int a,int b,int v,int n);
    //���ñ���
    int a=2,b=1,v=1,n=0;
    int t=0;//����ǣ��ɹ������Ϊ1
    int s=2048;//��⾫�ȣ���a,b,v��ȡֵ����
    printf("��������Ҫ��֤�Ƿ�Ϊͬ����������n��");
    scanf("%d",&n);
    //���޶���Χ��ѭ��ö�ٳ������
    for(a=2;a<=s;a++)
    {
        for(b=1;b<a;b++)
        {
            for(v=1;v<=s;v++)
            {
                //�ж��Ƿ������ĸ�����
                if(huzhi(a,b)&&jio(a,b)&&tiaojian(a,b)&&gongshi(a,b,v,n))
                {
                    printf("n=%d��ͬ����\n",n);
                    printf("��ʽ��a=%d,b=%d,v=%d\n",a,b,v);
                    t=1;
                    break;
                }
            }
            //�������ɹ�������ѭ��
            if(t==1)
            {
                break;
            }
        }
        //�������ɹ�������ѭ��
        if(t==1)
        {
            break;
        }
    }
    //���ھ�����δ�ҵ�������ʾ
    if(t==0)
    {
        printf("n=%d�ڸþ����ڲ���ͬ����",n);
    }
    return 0;
}

//����һ��a,b����
//�����ʷ���1,�����ʷ���0
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

//��������a,bһ����һż��
//������������1����������������0
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

//��������a,b����������a>b
//������������1����������������0
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

//�����ģ������жϹ�ʽ
//���㹫ʽ����1�������㹫ʽ����0
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
