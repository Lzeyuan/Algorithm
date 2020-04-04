#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int C[6];
    int V[6] = {1,5,10,50,100,500};
    for (int i = 0; i < 6; i++) {
        cin >> C[i];
    }

    int A;
    cin >> A;

    int ans = 0;
    int t;

    for (int i = 5; i >= 0; i--) {
        t = min(C[i], A/V[i]); 
        A -= t*V[i];
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
