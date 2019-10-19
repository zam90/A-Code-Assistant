#include <stdio.h>

int main(void)
{
    int num[3][3];
    int a, b;
    printf("请输入一个3*3的二维数组：\n");
    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < 3; a++)
            scanf("%d", &num[b][a]);
        getchar();
    }
    printf("\n转置数组矩阵为：\n");
    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < 3; a++)
            printf("%d ", num[a][b]);
        printf("\n");
    }
    return 0;
}
