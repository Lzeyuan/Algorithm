#include <iostream>

using namespace std;

//范围
int const MAX_V = 400;
int const MAX_M = 400;
int const MAX_K = 500;

//输入
int v;  //体积
int m;  //质量
int k;  //卡路里
int n;  //n种食物

int dp[MAX_M + 1][MAX_V + 1];

int main() {
    cin >> v >> m;
    cin >> n;

    int t_m, t_v, t_k;
    for (int i = 1; i <= n; i++) {
        cin >> t_v >> t_m >> t_k;
        
        for (int j = v; j >= t_v; j--) {
            for (int k = m; k >= t_m; k--) {
                dp[k][j] = max( dp[k][j], dp[k - t_m][j - t_v] + t_k);
            }
        }
    }
    cout << dp[m][v];
    return 0;
}