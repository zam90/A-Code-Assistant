
#include <string>
#include <iostream>
using namespace std;
#define MW 999999

//城市节点
struct City {
    string CityName,CityInfo;
    int CityNo;
};

//以邻接矩阵形式存储图中距离信息
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

//以邻接矩阵形式存储图中金额信息
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

//以邻接矩阵形式存储图中时间信息
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

//返回城市信息
void CityInfo(City c) {
    int i;
    cout << "请输入需要查询的城市编号：";
    cin >> i;
    c.CityNo = i;
    c.CityName = "号城市";
    c.CityInfo = "号城市的基本信息\n";
    cout << "城市编号：" << c.CityNo << "\n城市名称：" << i << c.CityName << "\n城市信息：这里是" << i << c.CityInfo << endl;
}

//弗洛伊德算法求最短路径
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

//调用Floyd函数并返回查询最小的结果
void Min(int z[10][10]) {
    int a, b;
    Floyd(z);
    cout << "请分别输入想要查询的两个城市的编号：" << endl;
    cin >> a >> b;
    if (a >= 0 && b >= 0 && a < 10 && b < 10)
        cout << "查询的数值为：" << z[a][b];
    else
        cout << "查询错误";
}

//主函数
int main()
{
    City c;
    int flag = 1;
    int Distance[10][10],Money[10][10],Time[10][10];
    CreateGraphDistance(Distance);
    CreateGraphMoney(Money);
    CreateGraphTime(Time);
    //功能菜单
    while (flag != 4) {
        cout << "欢迎来到民航售票系统" << endl;
        cout << "功能一览：\n0：查看两地间最短距离\n1：查看两地间最短时间\n2：查看两地间最少花费\n3：查看城市信息\n4：退出程序" << endl;
        cout << "请输入功能编号：";
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
            cout << "元\n" << endl;
            break;
        case 3:
            CityInfo(c);
            break;
        case 4:
            break;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    }
    cout << "您已退出系统，欢迎再次使用！\nPowered By JingYu Zhang" << endl;
    return 0;
}