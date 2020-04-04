#include <iostream>
#include <algorithm>

using namespace std;

//输入
int perm[100];

void solve1(int n) {
    do{
        for (int i = 1; i <= n; i++) {
            cout << perm[i] << ' ';
        }
        cout << endl;
    }while(next_permutation(perm+1, perm+n+1));

    cout << "==========原式===========" << endl;
    for (int i = 1; i <= n; i++) {
        cout << perm[i] << ' ';
    }
    cout << endl;
}

bool used[100];
int perm2[100];
void solve2(int pos, int n) {
    if (n + 1 == pos) {
        for (int i = 1; i <= n; i++) {
            cout << perm2[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            perm2[pos] = i;
            used[i] = true;
            solve2(pos + 1, n);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        perm[i] = i;
    }

    solve1(n);
    solve2(1, n);
    return 0;
}
