#include <iostream>

using namespace std;

//范围
int const MAX_N = 30;
int const MAX_V = 20000;

//输入
int V, n;
int Pack[MAX_N + 1];

//slove
int f[MAX_V + 1];
int slove(){
    for (int i = 1; i <= n; i++ ) {
        for (int j = V; j >= Pack[i]; j-- ) {
            f[j] = max( f[j], f[ j - Pack[i] ] + Pack[i] );
        }
        /*for (int j = 0; j <= V; j++ ) {
            cout << "  " << f[j];
        }
        cout << endl;*/
    }
    return f[V];
}

int main(){
    cin >> V;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Pack[i];
    }

    cout << V - slove();

    return 0;
}