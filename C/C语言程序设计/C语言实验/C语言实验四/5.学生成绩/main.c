#include<stdio.h>
#include<stdlib.h>

//����ṹ������
struct ST
{
int ID;
char name[20];
float score[3];
};
//�ṹ������ָ����Ϊ��������
float avg1(struct ST *p, int n)
{
float sum = 0, avg;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < 3; j++)
{
sum += p[i].score[j];
 }
 }
 avg = sum / n / 3;
 return avg;
}

//�����߷���ѧ����Ϣ
 void high(struct ST *p, int n)
 {
   int index = 0;
    float max = 0, sum = 0;
   for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < 3; j++)
         {
             sum = p[i].score[0] + p[i].score[1] + p[i].score[2];
             if (sum > max)
             {
                 max = sum;
                 index = i;
             }
         }
     }
    printf("���ѧ����ϢΪ:\n");
    printf("ѧ��:%d\n", p[index].ID);
   printf("����:%s\n", p[index].name);
    printf("�ɼ�:%.2f, %.2f, %.2f\n", p[index].score[0], p[index].score[1], p[index].score[2]);
 }

 int main()
 {
     int i, j;
   struct ST sts[5];
     for (i = 0; i < 5; i++)
    {
         printf("�������%d��ѧ����Ϣ\n", i+1);
         scanf("%d", &sts[i].ID);
       scanf("%s", sts[i].name);         printf("������Ƴɼ�\n");
         for (j = 0; j < 3; j++)
        {
            scanf("%f", &sts[i].score[j]);
       }
     }
    printf("ƽ���ɼ�Ϊ:%f\n", avg1(sts, 5));
   high(sts, 5);
    system("pause");
     return 0;
}
