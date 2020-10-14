
#include <string>
#include <iostream>
using namespace std;
#define MW 999999

//���нڵ�
struct City {
    string CityName,CityInfo;
    int CityNo;
};

//���ڽӾ�����ʽ�洢ͼ�о�����Ϣ
void CreateGraphDistance(int Distance[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            Distance[i][j] = MW;
        }
    }
    Distance[0][1] = 2000;
    Distance[0][2] = 1600;
    Distance[0][3] = 3500;
    Distance[1][2] = 1400;
    Distance[1][4] = 1300;
    Distance[1][9] = 1800;
    Distance[2][5] = 700;
    Distance[3][6] = 900;
    Distance[4][5] = 2600;
    Distance[4][7] = 1850;
    Distance[4][9] = 1900;
    Distance[5][6] = 1500;
    Distance[5][7] = 1860;
    Distance[5][8] = 1500;
    Distance[6][8] = 1900;
    Distance[7][8] = 5000;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == j) {
                Distance[i][i] = 0;
            }
            if (Distance[i][j] < MW) {}
            Distance[j][i] = Distance[i][j];
        }
    }
}

//���ڽӾ�����ʽ�洢ͼ�н����Ϣ
void CreateGraphMoney(int Money[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            Money[i][j] = MW;
        }
    }
    Money[0][1] = 100;
    Money[0][2] = 90;
    Money[0][3] = 130;
    Money[1][2] = 80;
    Money[1][4] = 75;
    Money[1][9] = 85;
    Money[2][5] = 50;
    Money[3][6] = 55;
    Money[4][5] = 120;
    Money[4][7] = 85;
    Money[4][9] = 95;
    Money[5][6] = 90;
    Money[5][7] = 85;
    Money[5][8] = 80;
    Money[6][8] = 90;
    Money[7][8] = 150;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == j) {
                Money[i][i] = 0;
            }
            if (Money[i][j] < MW) {}
            Money[j][i] = Money[i][j];
        }
    }
}

//���ڽӾ�����ʽ�洢ͼ��ʱ����Ϣ
void CreateGraphTime(int Time[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            Time[i][j] = MW;
        }
    }
    Time[0][1] = 3;
    Time[0][2] = 2;
    Time[0][3] = 4;
    Time[1][2] = 2;
    Time[1][4] = 1;
    Time[1][9] = 2;
    Time[2][5] = 1;
    Time[3][6] = 1;
    Time[4][5] = 2;
    Time[4][7] = 2;
    Time[4][9] = 2;
    Time[5][6] = 1;
    Time[5][7] = 1;
    Time[5][8] = 2;
    Time[6][8] = 2;
    Time[7][8] = 5;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == j) {
                Time[i][i] = 0;
            }
            if (Time[i][j] < MW) {}
            Time[j][i] = Time[i][j];
        }
    }
}

//���س�����Ϣ
void CityInfo(City c) {
    int i;
    cout << "��������Ҫ��ѯ�ĳ��б�ţ�";
    cin >> i;
    c.CityNo = i;
    c.CityName = "�ų���";
    c.CityInfo = "�ų��еĻ�����Ϣ\n";
    cout << "���б�ţ�" << c.CityNo << "\n�������ƣ�" << i << c.CityName << "\n������Ϣ��������" << i << c.CityInfo << endl;
}

//���������㷨�����·��
void Floyd(int e[10][10]) {
    int i, j, k;
    for (k = 0; k < 10; k++) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }        
        }
    }        
}

//����Floyd���������ز�ѯ��С�Ľ��
void Min(int z[10][10]) {
    int a, b;
    Floyd(z);
    cout << "��ֱ�������Ҫ��ѯ���������еı�ţ�" << endl;
    cin >> a >> b;
    if (a >= 0 && b >= 0 && a < 10 && b < 10)
        cout << "��ѯ����ֵΪ��" << z[a][b];
    else
        cout << "��ѯ����";
}

//������
int main()
{
    City c;
    int flag = 1;
    int Distance[10][10],Money[10][10],Time[10][10];
    CreateGraphDistance(Distance);
    CreateGraphMoney(Money);
    CreateGraphTime(Time);
    //���ܲ˵�
    while (flag != 4) {
        cout << "��ӭ��������Ʊϵͳ" << endl;
        cout << "����һ����\n0���鿴���ؼ���̾���\n1���鿴���ؼ����ʱ��\n2���鿴���ؼ����ٻ���\n3���鿴������Ϣ\n4���˳�����" << endl;
        cout << "�����빦�ܱ�ţ�";
        cin >> flag;
        switch (flag)
        {
        case 0:
            Min(Distance);
            cout << "km\n" << endl;
            break;
        case 1:
            Min(Time);
            cout << "h\n" << endl;
            break;
        case 2:
            Min(Money);
            cout << "Ԫ\n" << endl;
            break;
        case 3:
            CityInfo(c);
            break;
        case 4:
            break;
        default:
            cout << "�����������������룡" << endl;
            break;
        }
    }
    cout << "�����˳�ϵͳ����ӭ�ٴ�ʹ�ã�\nPowered By JingYu Zhang" << endl;
    return 0;
}