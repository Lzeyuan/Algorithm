#include <iostream>
#include <cstdio>

using namespace std;

//范围
int const MAX_C = 50000;
int const MAX_H = 5000;
int const MAX_V = MAX_C;
 
//输入
int C;  //马车容量
int H;  //稻草种类
int v[MAX_H + 1];   //稻草体积

//01背包问题
int dp[MAX_C + 1];
void ZeroOnePack() {
    for (int i = 1; i <= H; i++) {
        for (int j = C; j >= v[i] ; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
}

int main() {
    cin >> C >> H;
    for (int i = 1; i <= H; i++) {
        cin >> v[i];
    }

    ZeroOnePack();
    cout << dp[C];

    return 0;
}