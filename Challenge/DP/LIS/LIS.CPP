#include <iostream>
#include <cstring>

using namespace std;

//范围
int const MAX_N = 1E6;

//输入
int n;
int a[MAX_N];
int dp[MAX_N];

//LIS
void Lis() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;
        res = max(dp[i], res);
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i< n; i++) {
        cin >> a[i];
    }
    Lis();
    return 0;
}