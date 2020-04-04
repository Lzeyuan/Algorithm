#include <iostream>
#include <algorithm>

using namespace std;

int const MAX_N = 1E6;

//输入
int n, a[MAX_N];
int L;

int Min() {
    int minimum = INT32_MIN;
    for (int i = 0; i < n; i++) {
        minimum = max(min(a[i], L-a[i]), minimum);      //最终时间取决于路最长的蚂蚁，即取决于路该蚂蚁走，最短路，所需时间。（同向走不会撞车）
    }
    return minimum;
}

int Max() {
    int maximum = INT32_MIN;
    for (int i = 0; i < n; i++) {
        maximum = max(max(a[i],L - a[i]), maximum);     //最终时间取决于路最长的蚂蚁，即取决于路该蚂蚁走，最长路，所需时间。
    }
    return maximum;
}
 
int main() {
    cin >> L;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << Min() << endl;
    cout << Max() << endl;
    return 0;
}
