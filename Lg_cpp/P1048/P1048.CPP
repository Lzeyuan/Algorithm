#include <iostream>

using namespace std;

int const MAX_M = 100;
int const MAX_T = 1000;

//输入
int T, M;
int w[MAX_M], v[MAX_M];

int dp[MAX_T + 1];
int solve(){
    for( int i = 1; i <= M ; i++ ){
        for( int j = T; j >= w[i]; j-- ){
            dp[j] = max( dp[j], dp[ j - w[i] ] + v[i] );
        }
    }

    cout << dp[T];
    return 0;
}

int main(){
    cin >> T >> M;
    for( int i = 1; i <= M; i++ ){
        cin >> w[i] >> v[i];
    }

    solve();

    return 0;
}