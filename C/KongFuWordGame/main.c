#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int sm=100,gj=5,mf=2,fy=2,smsx=100;
    int mwsm=200,mwgj=15,mwfy=3;
    int caozuo=0,lj=0,canshu=0;
    char name[]="����ħ��";
    int duizhan(int sm,int gj,int fy,int mf,int mwsm,int mwgj,int mwfy,int canshu,char *name);
    printf("��Ϸ������......");
    Sleep(5000);
    printf("\n\n��ӭ���������������磡\n");
    Sleep(500);
    printf("����һ��������ʿ���վ���ɽ����\n");
    Sleep(500);
    printf("һ�죬������%s����������ǰȥ�ַ���\n",name);
    Sleep(500);
    printf("1����·\n2������·\n");
    Sleep(500);
    printf("��ѡ���Ƿ���·��");
    scanf("%d",&caozuo);
    if(caozuo==2){
        Sleep(500);
        printf("��֪Ϊʲô���������ˡ����ã�%s�������������㣡\n",name);
        Sleep(500);
        printf("��Ϸ����\n");
        return 0;
    }
    printf("�㿪ʼ������...\n");
    Sleep(500);
    printf("��ʼ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
    Sleep(500);
    duizhan(sm,gj,fy,mf,mwsm,mwgj,mwfy,1,name);
    return 0;
}

int duizhan(int sm,int gj,int fy,int mf,int mwsm,int mwgj,int mwfy,int canshu,char *name){
    int caozuo=0,lj=0;
    printf("��ʼս����\n");
    Sleep(500);
    for(;;)
    {
        printf("\n�غ�ѡ�\n0������\n1������\n2��ħ��\n3�����\n");
        Sleep(500);
        printf("��Ļغϣ�");
        scanf("%d",&caozuo);
        Sleep(500);
        if(caozuo==0){
            printf("�㿪ʼ������ģʽ���������ǣ�\n");
            gj=gj+4*canshu;
            fy=fy+2*canshu;
            mf=mf+10*canshu;
            Sleep(500);
            printf("��Ĺ���+%d ����+%d ħ��+%d\n",4*canshu,2*canshu,10*canshu);
            Sleep(500);
            printf("%s���㷢��������\n",name);
            Sleep(500);
            if(fy>=mwgj){
                printf("ʲô��û�з�����\n");
                Sleep(500);
                printf("%s���㰲Ȼ�����ǳ�����\n",name);
                Sleep(500);
                mwgj=mwgj+10*canshu;
                printf("%s����+%d\n",name,10*canshu);
                Sleep(500);
                printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
            else{
                lj=mwgj-fy;
                sm=sm-lj;
                printf("�������-%d\n",lj);
                Sleep(500);
                printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
        }
        if(caozuo==1){
            printf("���%s�����˹�����\n",name);
            lj=gj-mwfy;
            mwsm=mwsm-lj;
            Sleep(500);
            printf("%s����-%d\n",name,lj);
            Sleep(500);
            printf("%s�������ػ���\n",name);
            lj=mwgj-fy;
            sm=sm-lj;
            Sleep(500);
            printf("�������-%d\n",lj);
            Sleep(500);
            printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
            Sleep(500);
            printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
            Sleep(500);
        }
        if(caozuo==2){
            if(mf>=50){
                printf("���ħ����%s��������ˣ�\n",name);
                lj=mf;
                mwsm=mwsm-lj;
                mf=0;
                Sleep(500);
                printf("%s����-%d ���ħ��-%d\n",name,lj,lj);
                Sleep(500);
                printf("%s�������ػ���\n",name);
                lj=mwgj-fy;
                sm=sm-lj;
                Sleep(500);
                printf("�������-%d\n",lj);
                Sleep(500);
                printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
            else{
                printf("���ħ��������������%s��������\n",name);
                Sleep(500);
                printf("%s�������ػ���\n",name);
                lj=mwgj-fy;
                sm=sm-lj;
                Sleep(500);
                printf("�������-%d\n",lj);
                Sleep(500);
                printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
        }
        if(caozuo==3){
            printf("%s���㷢�𹥻���\n",name);
            Sleep(500);
            printf("������Ķ����%s�Ĺ�����%s�ǳ�����\n",name,name);
            Sleep(500);
            mwgj=mwgj+5*canshu;
            printf("%s����+%d\n",name,5*canshu);
            Sleep(500);
            printf("Ƭ��֮��%s��������Ԥıʲô��������������\n",name);
            Sleep(500);
            mwfy=mwfy+10*canshu;
            printf("%s����+%d\n",name,10*canshu);
            Sleep(500);
            printf("������%s�Ĺ������õ���Ƭ�̵���Ϣ\n",name);
            Sleep(500);
            sm=sm+10*canshu;
            mf=mf+10*canshu;
            printf("�������+%d ħ��+%d\n",10*canshu,10*canshu);
            Sleep(500);
            printf("��ĵ�ǰ���ԣ�������%d ������%d ������%d ħ����%d\n",sm,gj,fy,mf);
            Sleep(500);
            printf("%s��ǰ���ԣ�������%d ������%d ������%d\n",name,mwsm,mwgj,mwfy);
            Sleep(500);
        }
        if(sm<=20*canshu){
            printf("��������Σ������һϢ\n");
            Sleep(500);
        }
        if(sm<=0){
            printf("\n����ս%sʧ�ܣ���%s��ȥ����\n",name,name);
            Sleep(500);
            printf("��Ϸ����\n");
            return 0;
        }
        if(mwsm<=0){
            printf("\n���㲻иŬ���£��������ֽ�����%s����һ��\n",name);
            Sleep(500);
            printf("��������ձ�����������\n");
            Sleep(500);
            printf("��Ϸ����\n");
            return 0;
        }
    }
}
