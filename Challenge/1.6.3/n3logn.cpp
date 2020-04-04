#include <iostream>
#include <algorithm>

using namespace std;

int const MAX_N = 1E6;

//输入
int n, m, a[MAX_N];

bool Binary_search(int x) {
    int l = 0;
    int r = n;

    while(r - l >= 1) {
        int mid = (r+l)/2;
        if (a[mid] == x) return true;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }

    return false;
}

bool solve() {
    sort(a,a+n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (Binary_search(m-a[i]-a[j]-a[k]))
                    return true;
            }
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
