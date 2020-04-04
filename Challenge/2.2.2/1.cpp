#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

//范围
int const MAX_N = 1E5;

//输入
int n;
int S[MAX_N], T[MAX_N];

int solve() {
    pair<int,int> itv[MAX_N];

    for (int i = 0; i < n; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }

    sort(itv,itv+n);
    int ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> S[i];
    }

    for (int i = 0 ; i < n; i++) {
        cin >> T[i];
    }

    cout << solve() << endl;

    return 0;
}
