/* 
    01 背包问题
*/
#include <iostream>
#include <cstring>

using namespace std;

int const MAX_N = 10;

//输入
int n, m;
int w[MAX_N], v[MAX_N];

int f[MAX_N + 1][MAX_N + 1];

//先序DP(√)
int dp_Preorder(){
        for( int i = 1; i <= n ; i++ ){
            for( int j = w[i]; j <= m; j++ )
                f[i][j] = max( f[i - 1][j] , f[i - 1][j - w[i]] + v[i] );
    }
    return f[n][m];
}

//倒序DP
int dp_Reverseorder(){
        for( int i = n; i >= 1 ; i-- ){
            for( int j = m; j >=  w[i]; j-- )
                f[i][j] = max( f[i + 1][j] , f[i + 1][j - w[i]] + v[i] );
    }
    return f[1][m];
}

int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> w[i] >> v[i];
    }
    cin >> m;

    cout << "preoreader: " << dp_Preorder() << endl;

    memset( f, 0, sizeof(f) );
    cout << "reverse: " << dp_Reverseorder();


    return 0;
}