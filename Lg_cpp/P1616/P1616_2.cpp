#include <iostream>
#include <cstdio>

using namespace std;

//范围
int const MAX_M = 1E4;  //山药最大数目
int const MAX_T = 1E5;  //草药最大时间

//输入
int M;  //山药数目
int T;  //总采药时间
int t[MAX_M + 1];  //采药时间
int v[MAX_M + 1];   //药草价值

//完全背包问题
int dp[MAX_T + 1];
void ZeroOnePack() {
    for (int i = 1; i <= M; i++) {
        for (int j = t[i]; j <= T ; j++) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
}

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t[i] >> v[i];
    }

    ZeroOnePack();
    cout << dp[T];

    return 0;
}