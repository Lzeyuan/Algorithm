#include <iostream>

using namespace std;

//
int const MAX_N = 1E3;

//输入
int N;
int R;
int a[MAX_N];

int main() {
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    } 

    int i = 0;
    int ans = 0;
    while(i < N) {
        int s = a[i++];
        while(i < N && a[i] <= s + R) i++;
        int p = a[i-1];
        while(i < N && a[i] <= p + R) i++;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}
