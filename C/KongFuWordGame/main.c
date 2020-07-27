#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int sm=100,gj=5,mf=2,fy=2,smsx=100;
    int mwsm=200,mwgj=15,mwfy=3;
    int caozuo=0,lj=0,canshu=0;
    char name[]="混世魔王";
    int duizhan(int sm,int gj,int fy,int mf,int mwsm,int mwgj,int mwfy,int canshu,char *name);
    printf("游戏加载中......");
    Sleep(5000);
    printf("\n\n欢迎来到文字修仙世界！\n");
    Sleep(500);
    printf("你是一个隐居侠士，日居深山练功\n");
    Sleep(500);
    printf("一天，你听闻%s降世，决心前去讨伐！\n",name);
    Sleep(500);
    printf("1：上路\n2：不上路\n");
    Sleep(500);
    printf("请选择是否上路：");
    scanf("%d",&caozuo);
    if(caozuo==2){
        Sleep(500);
        printf("不知为什么，你退缩了。不久，%s降世便消灭了你！\n",name);
        Sleep(500);
        printf("游戏结束\n");
        return 0;
    }
    printf("你开始了征程...\n");
    Sleep(500);
    printf("初始属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
    Sleep(500);
    duizhan(sm,gj,fy,mf,mwsm,mwgj,mwfy,1,name);
    return 0;
}

int duizhan(int sm,int gj,int fy,int mf,int mwsm,int mwgj,int mwfy,int canshu,char *name){
    int caozuo=0,lj=0;
    printf("开始战斗！\n");
    Sleep(500);
    for(;;)
    {
        printf("\n回合选项：\n0：修炼\n1：攻击\n2：魔法\n3：躲避\n");
        Sleep(500);
        printf("你的回合：");
        scanf("%d",&caozuo);
        Sleep(500);
        if(caozuo==0){
            printf("你开始了修炼模式，功力大涨！\n");
            gj=gj+4*canshu;
            fy=fy+2*canshu;
            mf=mf+10*canshu;
            Sleep(500);
            printf("你的攻击+%d 防御+%d 魔法+%d\n",4*canshu,2*canshu,10*canshu);
            Sleep(500);
            printf("%s对你发动攻击！\n",name);
            Sleep(500);
            if(fy>=mwgj){
                printf("什么都没有发生！\n");
                Sleep(500);
                printf("%s看你安然无恙，非常生气\n",name);
                Sleep(500);
                mwgj=mwgj+10*canshu;
                printf("%s攻击+%d\n",name,10*canshu);
                Sleep(500);
                printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
            else{
                lj=mwgj-fy;
                sm=sm-lj;
                printf("你的生命-%d\n",lj);
                Sleep(500);
                printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
        }
        if(caozuo==1){
            printf("你对%s发起了攻击！\n",name);
            lj=gj-mwfy;
            mwsm=mwsm-lj;
            Sleep(500);
            printf("%s生命-%d\n",name,lj);
            Sleep(500);
            printf("%s对你给予回击！\n",name);
            lj=mwgj-fy;
            sm=sm-lj;
            Sleep(500);
            printf("你的生命-%d\n",lj);
            Sleep(500);
            printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
            Sleep(500);
            printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
            Sleep(500);
        }
        if(caozuo==2){
            if(mf>=50){
                printf("你的魔法对%s造成了重伤！\n",name);
                lj=mf;
                mwsm=mwsm-lj;
                mf=0;
                Sleep(500);
                printf("%s生命-%d 你的魔法-%d\n",name,lj,lj);
                Sleep(500);
                printf("%s对你给予回击！\n",name);
                lj=mwgj-fy;
                sm=sm-lj;
                Sleep(500);
                printf("你的生命-%d\n",lj);
                Sleep(500);
                printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
            else{
                printf("你的魔法仍需修炼，对%s不起作用\n",name);
                Sleep(500);
                printf("%s对你给予回击！\n",name);
                lj=mwgj-fy;
                sm=sm-lj;
                Sleep(500);
                printf("你的生命-%d\n",lj);
                Sleep(500);
                printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
                Sleep(500);
                printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
                Sleep(500);
            }
        }
        if(caozuo==3){
            printf("%s对你发起攻击！\n",name);
            Sleep(500);
            printf("你巧妙的躲避了%s的攻击，%s非常生气\n",name,name);
            Sleep(500);
            mwgj=mwgj+5*canshu;
            printf("%s攻击+%d\n",name,5*canshu);
            Sleep(500);
            printf("片刻之后，%s觉得你在预谋什么，对你有所警觉\n",name);
            Sleep(500);
            mwfy=mwfy+10*canshu;
            printf("%s防御+%d\n",name,10*canshu);
            Sleep(500);
            printf("你躲避了%s的攻击，得到了片刻的休息\n",name);
            Sleep(500);
            sm=sm+10*canshu;
            mf=mf+10*canshu;
            printf("你的生命+%d 魔法+%d\n",10*canshu,10*canshu);
            Sleep(500);
            printf("你的当前属性：生命：%d 攻击：%d 防御：%d 魔法：%d\n",sm,gj,fy,mf);
            Sleep(500);
            printf("%s当前属性：生命：%d 攻击：%d 防御：%d\n",name,mwsm,mwgj,mwfy);
            Sleep(500);
        }
        if(sm<=20*canshu){
            printf("你生命垂危，奄奄一息\n");
            Sleep(500);
        }
        if(sm<=0){
            printf("\n你挑战%s失败，被%s打去世了\n",name,name);
            Sleep(500);
            printf("游戏结束\n");
            return 0;
        }
        if(mwsm<=0){
            printf("\n在你不懈努力下，终于亲手结束了%s罪恶的一生\n",name);
            Sleep(500);
            printf("你的名字终被世人所铭记\n");
            Sleep(500);
            printf("游戏结束\n");
            return 0;
        }
    }
}
