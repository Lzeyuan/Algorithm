#include <iostream>
#include <cstring>

using namespace std;

//范围
int const MAX_SIZE = 100;

//输入
char s[MAX_SIZE + 1];
char t[MAX_SIZE + 1];

//Lcs
int dp[MAX_SIZE + 1][MAX_SIZE + 1];
void Lcs() {
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < strlen(t); j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j]+1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[strlen(s)][strlen(t)];
}

int main() {
    cin >> s >> t;
    Lcs();
    return 0;
}