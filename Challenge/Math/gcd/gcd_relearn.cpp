#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y,x%y): x;
}

int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if (b) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
} 

int main() {
    int a, b;
    int x, y;
    while(cin >> a >> b) {
        cout << "gcd(a,b) = " << gcd(a,b) << endl;
        cout << "extgcd(a,b) = " << extgcd(a,b,x,y) << endl;
        cout << "x = " << x << ", " << "y = " << y << endl; 
    }
    
    return 0;
}
