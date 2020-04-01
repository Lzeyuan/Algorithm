#include <iostream>

using namespace std;

//辗转相除法
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }

    int g = y/x;
    int counter = 0;
    int ss = 2;

    while (g > 1) {
        if (g % ss == 0) {
            counter++;
            while (g % ss == 0) {
                g /= ss;
            }
        }
        ss++;
    }
    cout << (1<<counter) << endl;
    return 0;
}