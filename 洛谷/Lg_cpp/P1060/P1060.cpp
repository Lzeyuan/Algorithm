#include <iostream>

using namespace std;

//范围
int const MAX_N = 30000;      //钱
int const MAX_M = 25;       //物品种数

//输入
int n, m;
int w[MAX_M + 1];       //重要度
int p[MAX_M + 1];       //价格

//01背包问题
int f[MAX_N + 1];
void slove() {
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= p[i]; j--) {
            f[j] = max( f[j], f[ j - p[i] ] + p[i] * w[i] );
        }
    }
    cout << f[n];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i] >> w[i];
    }

    slove();

    return 0;
}
