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
        printf("�����ַ�������(<10):");
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
        printf("ѧ�ţ�");
        scanf("%s",p->num);
        printf("������");
        scanf("%s",p->name);
        printf("�Ա�");
        scanf("%s",p->sex);
        printf("���䣺");
        scanf("%d",&p->age);
    }
        p->next=NULL;
        p=head;
        printf("\n ѧ��   ����   �Ա�   ����\n");
    while(p!=NULL)
    {
        printf("%4s%8s%6s%6d\n",p->num,p->name,p->sex,p->age);
        p=p->next;
    }
        printf("�������䣺");
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
        printf("û���ҵ� %d.",iage);
        p=head;
        printf("\n ѧ��   ����   �Ա�   ����\n");
    while(p!=NULL)
    {
        printf("%4s%8s",p->num,p->name);
        printf("%6s%6d\n",p->sex,p->age);
        p=p->next;
    }
}
