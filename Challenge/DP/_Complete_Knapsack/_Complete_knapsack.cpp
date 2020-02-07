#include <iostream>
#include <cstdio>

using namespace std;

int const MAX_N = 10000;
int const MAX_W = 100000;

//输入
int dp[MAX_N + 1][MAX_N + 1];
int n,W;
int v[MAX_N],w[MAX_N];

//完全背包问题
void solve1(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j <= W; j++ ){
            for( int k = 0; k * w[i] <= j; k++  ){
                dp[i + 1][j] = max( dp[i + 1][j], dp[i][ j - k * w[i] ] + k * v[i] );
            }
        }
    }

    cout << dp[n][W] << endl;
}

void solve2(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j <= W; j++ ){
            if( j < w[i] ){
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j]  = max( dp[i][j], dp[i + 1][ j - w[i] ] + v[i] );
            }
        }
    }

    cout << dp[n][W] << endl;
}

void solve3(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0 ; j <= W; j++ ){
            dp[i + 1] = max( dp[i + 1], dp[ j - w[i] ] + v[i] );
        }
    }
    cout << dp[W] << endl;
}

int main(){
    cin >> W >> n;
    for( int i = 0 ; i < n; i++ ){
        cin >> w[i] >> v[i];
    }

    solve1();

    solve2();

    solve3();

    return 0;
}

/*
输入：
3 7
3 4
4 5
2 3
*/