#include <stdio.h>

int main(void)
{
    int num[3][3];
    int a, b;
    printf("������һ��3*3�Ķ�ά���飺\n");
    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < 3; a++)
            scanf("%d", &num[b][a]);
        getchar();
    }
    printf("\nת���������Ϊ��\n");
    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < 3; a++)
            printf("%d ", num[a][b]);
        printf("\n");
    }
    return 0;
}
