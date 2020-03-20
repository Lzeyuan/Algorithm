#include <iostream>

using namespace std;

int const MAX_M = 1000;
int const MAX_X = 1000;
int const MAX_N = 100;

int a[MAX_N + 1];
int b[MAX_N + 1];
int c[MAX_N + 1];
int n,m,x;

int f[MAX_X + 1][MAX_M + 1];
void Pack() {
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= c[i]; j--) {
            for (int k = m; k >= b[i]; k--) {
                f[j][k] = max(f[j][k], f[j-c[i]][k-b[i]]+a[i]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    Pack();
    cout << f[x][m] << endl;
    return 0;
}