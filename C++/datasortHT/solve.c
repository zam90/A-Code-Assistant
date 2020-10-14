
#include"sqlite3.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static FILE *fp;
static long long DataSize=0;
//获取该有理数整数部分长度，若为整数即为自身长度
int getDot(const char* num,int len){
    for(register int i=0;i<len;i++){
        if(num[i]=='.') return i;
    }
    return len;
}

//判断是否为无穷大
int isInf(const char *num){
    return num[0]=='I'&&num[1]=='n'&&num[2]=='f';
}
//
int compare_number(void * pApp, int len_a, const void *text_a, int len_b, const void *text_b){
    register char *a=(char*)text_a,*b=(char*)text_b;
    if(isInf(a))return 1;
    else if(isInf(b))return -1;
    register int ad=getDot(a,len_a);
    register int bd=getDot(b,len_b);
    if(ad-bd) return ad-bd;
    while(len_a>0&&len_b>0&&*a++==*b++)len_a--,len_b--;
    --a,--b;
    if(*a==*b) return len_a-len_b;
    return ((*a<*b)?-1:1);
}



int inline colcallback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        fprintf(fp,"%s\n", argv[i] ? argv[i] : "NULL");
    }
    return 0;
}
int inline countcallback(void *data, int argc, char **argv, char **azColName){
    DataSize=atoll(argv[0]);
    fprintf(fp,"共处理 %s 个数， ", argv[0]);
    return 0;
}
int inline countInfcallback(void *data, int argc, char **argv, char **azColName){
    DataSize-=atoll(argv[0]);
    fprintf(fp,"其中 %lld 个有理数， ", DataSize);
    fprintf(fp,"有 %s 个为 Inf。 ", argv[0]);
    return 0;
}
int inline countIntcallback(void *data, int argc, char **argv, char **azColName){
    DataSize-=atoll(argv[0]);
    fprintf(fp,"一共有 %lld 个整数， 有 %s 个小数。\n", DataSize, argv[0]);
    return 0;
}
int print_from(sqlite3 *db){

    sqlite3_exec(db,"select count(number) from sorted_num",countcallback,NULL,NULL);
    sqlite3_exec(db,"select count(number) from sorted_num where number == \"Inf\"",countInfcallback,NULL,NULL);
    sqlite3_exec(db,"select count(number) from sorted_num where number like \"%%.%%\"",countIntcallback,NULL,NULL);
    sqlite3_exec(db,"select * from sorted_num",colcallback,NULL,NULL);
}

int print_to_file(sqlite3 *db,const char *filename){
    fp=fopen64(filename,"w+");
    print_from(db);
}
int print_from_file(sqlite3 *db,const char *filename){
    fp=fopen64(filename,"w+");
    sqlite3_exec(db,"select count(number) from raw_num",countcallback,NULL,NULL);
    sqlite3_exec(db,"select count(number) from raw_num where number == \"Inf\"",countInfcallback,NULL,NULL);
    sqlite3_exec(db,"select count(number) from raw_num where number like \"%%.%%\"",countIntcallback,NULL,NULL);
    sqlite3_exec(db,"select * from raw_num",colcallback,NULL,NULL);
}

int print_to_stdout(sqlite3 *db){
    fp=stdout;
    print_from(db);
}

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    const char * fromfile="raw.txt",*txtfile="data.txt";

    //fp=fopen64("s.txt","w+");
    sqlite3_open("Temp",&db);
    sqlite3_exec(db,"PRAGMA SYNCHRONOUS = OFF",0,0,0);

    time_t start,end;
    printf("产生随机数中\n产生速度由您的电脑性能决定！我的省电模式下用时为119s！请耐心等待文件生成！！！\n");
    time(&start);
    sqlite3_exec(db,"create table raw_num (number TEXT)",NULL,NULL,NULL);
    sqlite3_stmt *stmt;
    sqlite3_prepare(db,"insert into raw_num VALUES(?)",29,&stmt,NULL);
    for (int i = 0; i < 1e4; i++){
        sqlite3_reset(stmt);
        if((i>>3)&1)sqlite3_bind_double(stmt,1,(double)rand()/rand()+rand());
        else sqlite3_bind_int(stmt,1,rand());
        sqlite3_step(stmt); 
    }
    print_from_file(db,fromfile);
    time(&end);
    printf("产生随机数完成，共用时 %lld s\n",end-start);
    printf("请查看 %s 文件\n",fromfile);
    char Go[8]={0};
    while(Go[0]!='c'&&Go[0]!='o'&&Go[0]!='n'&&Go[0]!='t'&&Go[0]!='i'&&Go[0]!='n'&&Go[0]!='u'&&Go[0]!='e'){
        puts("请输入 continue 继续");
        gets(Go);
    }
    sqlite3_finalize(stmt);


    sqlite3_create_collation(db,"COMPARE_NUMBER",SQLITE_UTF8,NULL,compare_number);
    time(&start);
    sqlite3_exec(db,"create table sorted_num (number TEXT)",NULL,NULL,NULL);
    printf("排序ing!!!\n");
    sqlite3_exec(db,"insert into sorted_num (number) select (number) from raw_num order by number collate COMPARE_NUMBER",NULL,NULL,NULL);
    print_to_file(db,txtfile);
    time(&end);
    printf("排序完成!!!\n共用时 %lld s\n请查看 %s 文件!\n",end-start,txtfile);
    //sqlite3_exec(db,"select * from sorted_num",callback,NULL,NULL);
    sqlite3_close(db);
    remove("Temp");
    //printf("%d",compare_number(NULL,16,"9991.44217789866",3,"Inf"));
    return 0;
}
