#include <iostream>
#include <cstdio>

using namespace std;

//范围
int const MAX_N = 1E4;    //樱花树最大种类
int const MAX_T = 1E3;      //最大赏花时间

//输入
int Te1, Te2;   //现在时间
int Ts1, Ts2;   //上学时间
int DT;   //总时间 
int n;  //n种樱花树
int C[MAX_N + 1];   //美学值
int P[MAX_N + 1];   //观看次数
int T[MAX_N + 1];   //耗费时间

int dp[MAX_T + 1];  //DP数组

//01背包问题
void ZeroOnePack(int t, int v) {
    for (int j = DT; j >= t; j--) {
        dp[j] = max(dp[j], dp[j - t] + v);
    }
}

//完全背包问题
void CompletePack(int t, int v) {
    for (int j = t; j <= DT; j++) {
        dp[j] = max(dp[j], dp[j - t] + v);
    }
}

//多重背包问题
void MultiplePack(int i, int m) {
    if (DT <= m * T[i]) {
        CompletePack(T[i], C[i]);
        return;
    }

    int k = 1;
    while (m > k) {
        ZeroOnePack(T[i] * k, C[i] * k);
        m -= k;
        k = k * 2;
    }
    ZeroOnePack(T[i] * m, C[i] * m);
}

//混合背包问题
void MixPack() {
    for (int i = 1; i <= n; i++) {
        if (P[i] == 0) {    //完全背包问题
            CompletePack(T[i], C[i]);
        } else if (P[i] == 1) {     //01背包问题
            ZeroOnePack(T[i], C[i]);
        } else {        //多重背包问题
            MultiplePack(i, P[i]);
        }
    }
}

int main() {
    scanf("%d:%d %d:%d %d", &Te1, &Te2, &Ts1, &Ts2, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &T[i], &C[i], &P[i]);
    }

    //计算时间
    DT = (Ts1 - Te1) * 60 + (Ts2 - Te2);

    MixPack();

    cout << dp[DT];

    return 0;
}