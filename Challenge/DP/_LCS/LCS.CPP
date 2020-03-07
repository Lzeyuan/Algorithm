#include <iostream>

using namespace std;

//范围
int const MAX_SIZE = 1E3 + 1;

//输入
int n, m;

char s[MAX_SIZE], t[MAX_SIZE];

int dp[MAX_SIZE][MAX_SIZE];

void slove() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                cout << s[i] << ' ';
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    printf("\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d", dp[n][m]);
}

int main(){
    cin >> n >> m;
    cin >> s >> t;
    slove();
    return 0;
}