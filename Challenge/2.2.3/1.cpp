#include <iostream>

using namespace std;

//范围
int const MAX_N = 2E3;

//输入
int N;
char S[MAX_N+1];

int main() {
    cin >> N >> S;
    int a = 0, b = N-1;
    while(a <= b) {
        bool left = false;
        for (int i = 0; i <= (b-a)/2; i++) {
            if (S[a+i] < S[b-i]) {
                left = true;
                break;
            } else if (S[a+i] > S[b-i]) {
                left = false;
                break;
            }
        }
        if (left) {
            putchar(S[a++]);
        } else {
            putchar(S[b--]);
        }
    }

    return 0;
}
