#include <iostream>
#include <algorithm>


using namespace std;

int const MAX_N = 50;

//输入
int n, m, a[MAX_N];
int k[MAX_N*MAX_N];


bool Binary_search(int x) {
    int l = 0;
    int r = n;

    while(r - l >= 1) {
        int mid = (r+l)/2;
        if (k[mid] == x) return true;
        if (k[mid] < x) l = mid + 1;
        else r = mid;
    }

    return false;
}

bool solve() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k[i*n + j] = a[i] + a[j];
        }
    }

    sort(k,k+n*n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Binary_search(m-a[i]-a[j]))
                return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (solve())
        puts("yes");
    else
        puts("no");
    
    return 0;
}
