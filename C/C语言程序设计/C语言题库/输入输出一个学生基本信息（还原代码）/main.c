#include<stdio.h>

/******start******/
int main()
{
    struct
    {
        int number;
        char name[999];
        int age;
        float score;
    }st1;
    printf("Input the info:\n");
    scanf("%d %s %d %f",&st1.number,&st1.name,&st1.age,&st1.score);
/******end******/
	printf("Output:\n");
	printf("number:%d\n", st1.number);
	printf("name:%s\n", st1.name);
	printf("age:%d\n", st1.age);
	printf("score:%.2f\n", st1.score);

	return 0;
}
