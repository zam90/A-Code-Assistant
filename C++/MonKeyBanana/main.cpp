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
int a, b, c;//a ���� b���� c�㽶
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
        printf("������%dλ����������\n", w);
    }
    else if (x == 1 && z == 1) {
        //printf("������λ��%d��������\n",w);
        printf("������%dλ��ժ���㽶\n", w);
    }
    else if (x == 0 && y != w) {
        printf("���ӿ��ֵ���%dλ��\n", w);
    }
    else if (x == 0 && y == w) {
        printf("���������ӵ���λ��%d\n", w);
    }
}
int step = 1;
void print(int e)
{
    int w, x, y, z, close;
    if (pa[e] != -1) {
        print(pa[e]);
        Node node = nodes[e];
        w = node.w;//����λ��
        x = node.x;//�Ƿ���������
        y = node.y;//����λ��
        z = node.z;//�Ƿ�ժ���㽶
        //printf("\t");
        printf("��%d�� :", step++);
        go(w, x, y, z);
    }
}
void getBana()
{
    int w, x, y, z;
    int head, tail;
    memset(pa, -1, sizeof(pa));
    head = tail = 0;
    printf("���ӣ����ӣ��㽶�ĳ�ʼλ�÷ֱ�Ϊ%d %d %d\n\n", a, b, c);
    if (a == b && b == c) {
        printf("������λ��%d��������\n", a);
        printf("������%dλ��ժ���㽶\n", a);
        return;
    }
    if (b == c) {//���ӳ�ʼλ�����㽶λ����ͬ ������������

        if (b > a) {
            while (a < b) {
                ++a;
                printf("���ӿ��ֵ���%d\n", a);
            }
        }
        else {
            while (a > b) {
                --a;
                printf("���ӿ��ֵ���%d\n", a);
            }
        }
        printf("������λ��%d��������\n", a);
        printf("������%dλ��ժ���㽶\n", a);
    }

    nodes[tail].w = a;
    nodes[tail].x = 0;
    nodes[tail].y = b;
    nodes[tail].z = 0;
    tail++;
    while (head < tail) {
        Node node = nodes[head];
        w = node.w;//����λ��
        x = node.x;//�Ƿ���������
        y = node.y;//����λ��
        z = node.z;//�Ƿ�ժ���㽶
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
            if (w == y) {//���������� ������ͬһλ��
                for (int i = 0; i < 2; ++i) {
                    int nw = w + dir[i][1];
                    if (nw < 0) continue;
                    if (w == y && getDis(c, nw) > getDis(c, w)) continue;
                    pa[tail] = head;
                    nodes[tail].w = nw;//��ǰ��
                    nodes[tail].x = 0;
                    nodes[tail].y = nw;
                    nodes[tail].z = 0;
                    nodes[tail].close = 1;
                    tail++;
                    pa[tail] = head;
                    nodes[tail].w = nw;//�����ӳ���ժ
                    nodes[tail].x = 1;
                    nodes[tail].y = nw;
                    nodes[tail].z = 0;
                    tail++;

                }
            }
            if (w != y) {//����������  ����ͬһλ��
                for (int i = 0; i < 2; ++i) {
                    int nw = w + dir[i][1];
                    if (nw < 0) continue;
                    pa[tail] = head;
                    nodes[tail].w = nw;//�����ӳ���ժ
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
    cin >> a >> b >> c;//����ʾ����8 5 9
    getBana();

    return 0;
}