#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<cstring>
#include<cmath>
#define INF 0x3f3f3f3f
#define MAX 100000
using namespace std;
int a, b, c;//a 猴子 b箱子 c香蕉
int dir[2][2] = { {0,-1},{0,1} };
struct Node {
    int w, x, y, z;
    int close;
};
int pa[MAX];
int endd;
Node nodes[MAX];
int getDis(int x1, int x2) {
    return abs(x2 - x1);
}

void go(int w, int x, int y, int z)
{
    if (x == 1 && z == 0) {
        printf("猴子在%d位置爬上箱子\n", w);
    }
    else if (x == 1 && z == 1) {
        //printf("猴子在位置%d爬上箱子\n",w);
        printf("猴子在%d位置摘到香蕉\n", w);
    }
    else if (x == 0 && y != w) {
        printf("猴子空手到达%d位置\n", w);
    }
    else if (x == 0 && y == w) {
        printf("猴子推箱子到达位置%d\n", w);
    }
}
int step = 1;
void print(int e)
{
    int w, x, y, z, close;
    if (pa[e] != -1) {
        print(pa[e]);
        Node node = nodes[e];
        w = node.w;//猴子位置
        x = node.x;//是否在箱子上
        y = node.y;//箱子位置
        z = node.z;//是否摘到香蕉
        //printf("\t");
        printf("第%d步 :", step++);
        go(w, x, y, z);
    }
}
void getBana()
{
    int w, x, y, z;
    int head, tail;
    memset(pa, -1, sizeof(pa));
    head = tail = 0;
    printf("猴子，箱子，香蕉的初始位置分别为%d %d %d\n\n", a, b, c);
    if (a == b && b == c) {
        printf("猴子在位置%d爬上箱子\n", a);
        printf("猴子在%d位置摘到香蕉\n", a);
        return;
    }
    if (b == c) {//箱子初始位置与香蕉位置相同 不能往下走了

        if (b > a) {
            while (a < b) {
                ++a;
                printf("猴子空手到达%d\n", a);
            }
        }
        else {
            while (a > b) {
                --a;
                printf("猴子空手到达%d\n", a);
            }
        }
        printf("猴子在位置%d爬上箱子\n", a);
        printf("猴子在%d位置摘到香蕉\n", a);
    }

    nodes[tail].w = a;
    nodes[tail].x = 0;
    nodes[tail].y = b;
    nodes[tail].z = 0;
    tail++;
    while (head < tail) {
        Node node = nodes[head];
        w = node.w;//猴子位置
        x = node.x;//是否在箱子上
        y = node.y;//箱子位置
        z = node.z;//是否摘到香蕉
        //go(w,x,y,z);
        if (x == 1 && z == 1) {
            endd = head;
            break;
        }
        if (x == 1 && w == c) {
            pa[tail] = head;
            nodes[tail].w = w;
            nodes[tail].x = 1;
            nodes[tail].y = y;
            nodes[tail].z = 1;
            tail++;
        }
        if (x != 1) {
            if (w == y) {//不在箱子上 并且在同一位置
                for (int i = 0; i < 2; ++i) {
                    int nw = w + dir[i][1];
                    if (nw < 0) continue;
                    if (w == y && getDis(c, nw) > getDis(c, w)) continue;
                    pa[tail] = head;
                    nodes[tail].w = nw;//往前推
                    nodes[tail].x = 0;
                    nodes[tail].y = nw;
                    nodes[tail].z = 0;
                    nodes[tail].close = 1;
                    tail++;
                    pa[tail] = head;
                    nodes[tail].w = nw;//上箱子尝试摘
                    nodes[tail].x = 1;
                    nodes[tail].y = nw;
                    nodes[tail].z = 0;
                    tail++;

                }
            }
            if (w != y) {//不在箱子上  不在同一位置
                for (int i = 0; i < 2; ++i) {
                    int nw = w + dir[i][1];
                    if (nw < 0) continue;
                    pa[tail] = head;
                    nodes[tail].w = nw;//上箱子尝试摘
                    nodes[tail].x = 0;
                    nodes[tail].y = b;
                    nodes[tail].z = 0;
                    tail++;
                }
            }
        }
        head++;
    }
    //        printf("%d\n",endd);
    //        for(int i = 0; i < 20; ++i){
    //        	printf("%d ",pa[i]);
    //		}
    print(endd);
}


int main()
{
    ios::sync_with_stdio(false);
    srand((unsigned)time(NULL));
    a = rand() % (10 - 0) + 1;
    b = rand() % (10 - 0) + 1;
    c = rand() % (10 - 0) + 1;
    cin >> a >> b >> c;//输入示例：8 5 9
    getBana();

    return 0;
}