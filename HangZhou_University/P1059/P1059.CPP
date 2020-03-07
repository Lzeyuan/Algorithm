#include <iostream>
#include <cstring>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

//范围
int const MAX_N = 6;
int const MAX_V = 20000;

//输入
int n = 0;  //石头种数
long long K;  //石头平分价值
int w[MAX_N + 1] = {0, 1, 2, 3, 4, 5, 6};  //石头价值
int m[MAX_N + 1];   //石头个数

int dp[MAX_V * 21];  //DP数组
void MultiplePack() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= 6; i++) {
        for (long long j = 0; j <= K; j++) {
            //cout << j << endl;
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < w[i] || dp[j - w[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - w[i]] - 1;
            }
        }
    }
    /*for (int i = 1; i <= 6; i++) {
        cout << dp[i] << ' ';
    }
    cout << endl;*/
}

int main(){
    int times = 0;
    while (~scanf("%d%d%d%d%d%d", &m[1], &m[2], &m[3], &m[4], &m[5], &m[6]) && (m[1] + m[2] + m[3] + m[4] + m[5] + m[6])) {
        times++;
        K = 0;
        for (int i = 1; i <= 6; i++) {
            if (m[i]) {
                K += w[i] * m[i];
            }
        }

        cout << "Collection #" << times << ':' << endl;
        if (K % 2 == 0){
            K /= 2;
            MultiplePack();
            if (dp[K] >= 0)
                cout << "Can be divided." << endl;
            else
                cout << "Can't be divided." << endl;
        } else
            cout << "Can't be divided." << endl;
        cout << endl;
    }
    return 0;
}