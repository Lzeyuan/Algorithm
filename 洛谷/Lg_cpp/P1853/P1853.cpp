#include <iostream>

using namespace std;

//范围
int const MAX_N = 40;
int const MAX_A = 1E4;

//输入
int s;  //最初总资产
int n;  //年数
int d;  //债券种类
long long a[MAX_N + 1];    //投资额
long long b[MAX_N + 1];    //年利率

long long f[MAX_A];
int CompletePack() {
    for (int i = 1 ; i <= d; i++) {
        for (int j = a[i]; j <= s/1000; j++) {
            f[j] = max(f[j], f[j - a[i]] + b[i]);
        }
    }
    return f[s/1000];
}

int main() {
    cin >> s >> n >> d;
    for (int i = 1; i <= d; i++) {
        cin >> a[i] >> b[i];
        a[i] /= 1000;
    }

    for (int i = 1; i <= n; i++) {
        s += CompletePack();
    }
    cout << s;
    return 0;
}