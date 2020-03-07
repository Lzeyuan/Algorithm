#include <iostream>

using namespace std;

//范围
int const MAX_M = 1E5;  //种类持有数
int const MAX_W = 4E4;  //满载量
int const MAX_N = 100;  //种类

//输入
int n;  //种类数
int W;  //最大载重
int v[MAX_N + 1];   //价值
int w[MAX_N + 1];   //重量
int m[MAX_N + 1];   //持有数

int f[MAX_W + 1];       //dp数组

//01背包问题
void ZeroOnePack(int w, int v) {
    for (int j = W; j >= w; j--) {
        f[j] = max(f[j], f[j - w] + v);
    }
}

void CompletePack(int i) {
    for (int j = w[i]; j <= W; j++) {
        f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
}

void MultiplePack(int i) {
    if (m[i] * w[i] >= W) {
        CompletePack(i);
        return;
    }
    int k = 1;
    int t = m[i];
    while (k < t) {
        ZeroOnePack(k * w[i], k * v[i]);
        t -= k;
        k = k * 2;
    }
    ZeroOnePack(t * w[i], t * v[i]);
}

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> m[i];
        MultiplePack(i);
    }

    cout << f[W];
    return 0;
}