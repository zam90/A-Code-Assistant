#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
int a = 1, b = 1;
int ans = 0;
int graph[10][10] = { 0 };
int color[10] = { 0 };

bool ColorOK(int Point)
{
    for (int k = 1; k <= n; k++)
    {
        if (graph[Point][k] && color[Point] == color[k])
        {
            return false;
        }
    }
    return true;
}

void backtrack(int StartPoint)
{
    if (StartPoint > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", color[i]);
        }
        ans++;
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            color[StartPoint] = i;
            if (ColorOK(StartPoint))
            {
                backtrack(StartPoint + 1);
            }
            color[StartPoint] = 0;
        }
    }
}

int main()
{
    int FLAG = 1;
    cout << "请输入顶点个数n和颜色数量m：";
    cin >> n >> m;
    cout << "请输入顶点间关系，按0结束输入\n";
    while (FLAG)
    {
        cin >> a;
        if (a == 0) {
            FLAG = 0;
        }
        else {
            cin >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
    }
    backtrack(1);
    printf("Total=%d", ans);
    return 0;
}