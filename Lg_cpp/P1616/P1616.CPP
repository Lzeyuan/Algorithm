#include <iostream>
#include <cstdio>

using namespace std;

int const MAX_N = 10000;
int const MAX_W = 100000;

//输入
int dp[MAX_W];
int n,W;
int v[MAX_N],w[MAX_N];

//完全背包问题
void solve2(){
    for( int i = 0; i < n; i++ ){
        for( int j = w[i]; j <= W; j++ ){
            dp[j] = max( dp[j], dp[ j - w[i] ] + v[i] );
        }
    }

    cout << dp[W];
}

int main(){
    cin >> W >> n;
    for( int i = 0 ; i < n; i++ ){
        cin >> w[i] >> v[i];
    }
    solve2();
    return 0;
}

/*
7 3
3 4
4 5
2 3
*/