#include <iostream>

using namespace std;
int n, m, d;
int cij[50][50], wij[50][50];
int cw = 0, cp = 0;
int MaxW = 1000000;
int x[100];
int x1[100];
void machine(int t) {
    if (t >= n) {
        if (cw < MaxW) {
            MaxW = cw;
            for (int i = 0; i < n; i++) {
                x1[i] = x[i];
            }
        }
        return;
    }
    for (int i = 0; i < m; i++) {
        cp += cij[t][i];
        cw += wij[t][i];
        x[t] = i;
        if (cp <= d && cw <= MaxW) {
            machine(t + 1);
        }
        cp -= cij[t][i];
        cw -= wij[t][i];
    }
}
int main()
{
    cin >> n >> m >> d;
    memset(x1, 0, sizeof(x1));
    memset(x, 0, sizeof(x));
    memset(cij, 0, sizeof(cij));
    memset(wij, 0, sizeof(wij));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cij[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> wij[i][j];
        }
    }
    machine(0);
    cout << MaxW << endl;
    for (int i = 0; i < n; i++) {
        cout << x1[i] + 1 << " ";
    }
    return 0;
}