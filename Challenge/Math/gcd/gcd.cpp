#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    
    if (b) {
        d = extgcd(b, a%b , y, x);
        // y -= (a/b)*x;
        // y = y - (a/b)*x;
        y = x-(a/b)*b*y;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
    int x, y;
    x = y = -10086;
    cout << gcd(4,11) << endl;
    cout << extgcd(4, 11, x, y) << endl;
    cout << x << y << endl;
    return 0;
}
