#include <iostream>
#include <cstdio>

using namespace std;

//范围
int const MAX_DT = 1E3;
int const MAX_N = 1E4;

//输入
int DT; //可用总时间
int n;
int T[MAX_N + 1];   //消耗时间
int C[MAX_N + 1];   //看树价值
int P[MAX_N + 1];   //看树次数

int dp[MAX_DT + 1];     //DP数组

//01背包问题
void ZeroOnePack(int t, int c) {
    for (int j = DT; j >= t; j--) {
        dp[j] = max(dp[j], dp[j - t] + c);
    }
}

//完全背包问题
void CompletePack(int i) {
    for (int j = T[i]; j <= DT; j++) {
        dp[j] = max(dp[j], dp[j - T[i]] + C[i]);
    }
}

//多重背包问题
void MultiplePack(int i) {
    if (P[i] * T[i] >= DT) {    //完全背包问题
        CompletePack(i);
    }
    int k = 1;
    int M = P[i];
    while (M > k) {
        ZeroOnePack(k * T[i], k * C[i]);
        M -= k;
        k *= 2;
    }
    ZeroOnePack(M * T[i], M * C[i]);
}

//混合背包问题
void MixPack() {
    for (int i = 1; i <= n; i++) {
        if (P[i] == 0) {    //完全背包问题
            CompletePack(i);
        } else if (P[i] == 1) {    //01背包问题
            ZeroOnePack(T[i], C[i]);
        } else {    //多重背包问题
            MultiplePack(i);
        }
    }
}

int main() {
    int h1, m1; //开始时间
    int h2, m2; //结束时间
    
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    DT = (h2 - h1) * 60 + (m2 - m1);    //计算剩余总时间
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &T[i], &C[i], &P[i]);
    }
    //混合背包问题
    MixPack();
    
    cout << dp[DT];

    return 0;
}