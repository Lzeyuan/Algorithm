#include <iostream>
#include <algorithm>

using namespace std;

int const MAX_N = 1E6;

//输入
int n, a[MAX_N];

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int C = a[i] + a[j] + a[k];
                int m = max(a[i], max(a[j], a[k]));
                int res = C - m;

                if (res > m) {
                    ans = max(ans, C);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
