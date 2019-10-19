#include<stdio.h>
#include<stdlib.h>

//定义结构体类型
struct ST
{
int ID;
char name[20];
float score[3];
};
//结构体数组指针作为函数参数
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

//输出最高分数学生信息
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
    printf("最高学生信息为:\n");
    printf("学号:%d\n", p[index].ID);
   printf("姓名:%s\n", p[index].name);
    printf("成绩:%.2f, %.2f, %.2f\n", p[index].score[0], p[index].score[1], p[index].score[2]);
 }

 int main()
 {
     int i, j;
   struct ST sts[5];
     for (i = 0; i < 5; i++)
    {
         printf("请输入第%d个学生信息\n", i+1);
         scanf("%d", &sts[i].ID);
       scanf("%s", sts[i].name);         printf("输入各科成绩\n");
         for (j = 0; j < 3; j++)
        {
            scanf("%f", &sts[i].score[j]);
       }
     }
    printf("平均成绩为:%f\n", avg1(sts, 5));
   high(sts, 5);
    system("pause");
     return 0;
}
