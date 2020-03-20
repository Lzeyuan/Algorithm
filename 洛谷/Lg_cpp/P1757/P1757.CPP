#include <iostream>

using namespace std;

//范围
int const MAX_M = 1E3;
int const MAX_N = 1E3;
int const MAX_T = 1E2;

//输入
int n;  //n件物品
int m;  //总量m
int a[MAX_N + 1];   //物品重量
int b[MAX_N + 1];   //物品价值
int c[MAX_N + 1];   //所属组
int c_amount[MAX_N + 1];   //每组有多少件
int c_number[MAX_N + 1][MAX_N + 1]; //每组每件的编号
int c_now = 0;  //共有多少组

//分组背包
int dp[MAX_M + 1];
void GroupPack() {
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >=0; j--) {
            for (int k = 1; k <= c_amount[i]; k++) {
                if (j >= a[c_number[i][k]])
                    dp[j] = max(dp[j], dp[j - a[c_number[i][k]]] + b[c_number[i][k]]);
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c_now = max(c_now, c[i]);
        c_amount[c[i]]++;
        c_number[c[i]][c_amount[c[i]]] = i;
    }

    GroupPack();

    cout << dp[m] << endl;
    return 0;
}