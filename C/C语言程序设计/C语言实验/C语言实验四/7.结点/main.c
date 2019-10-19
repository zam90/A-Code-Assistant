#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)

struct student
{
    char num[6];
    char name[8];
    char sex[2];
    int age;
    struct student *next;
}stu[10];

void main()
{
    struct student *p,*pt,*head;
    int i,length,iage,flag=1;
    int find=0;
    while(flag==1)
    {
        printf("输入字符串长度(<10):");
        scanf("%d",&length);
        if(length<10)
        flag=0;
    }
    for (i=0;i<length;i++)
    {
        p=(struct student * ) malloc(LEN);
        if(i==0)
        head=pt=p;
        else
        pt->next=p;
        pt=p;
        printf("学号：");
        scanf("%s",p->num);
        printf("姓名：");
        scanf("%s",p->name);
        printf("性别：");
        scanf("%s",p->sex);
        printf("年龄：");
        scanf("%d",&p->age);
    }
        p->next=NULL;
        p=head;
        printf("\n 学号   姓名   性别   年龄\n");
    while(p!=NULL)
    {
        printf("%4s%8s%6s%6d\n",p->num,p->name,p->sex,p->age);
        p=p->next;
    }
        printf("输入年龄：");
        scanf("%d",&iage);
        pt=head;
        p=pt;
    if(pt->age==iage)
    {
        p=pt->next;
        head=pt=p;
        find=1;
    }
    else
        pt=pt->next;
    while(pt!=NULL)
    {
        if(pt->age==iage)
        {
        p->next=pt->next;
        find=1;
        }
    else
        p=pt;
        pt=pt->next;
        }
    if(!find)
        printf("没有找到 %d.",iage);
        p=head;
        printf("\n 学号   姓名   性别   年龄\n");
    while(p!=NULL)
    {
        printf("%4s%8s",p->num,p->name);
        printf("%6s%6d\n",p->sex,p->age);
        p=p->next;
    }
}
