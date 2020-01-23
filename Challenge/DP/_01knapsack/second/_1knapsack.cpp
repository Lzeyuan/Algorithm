#include <iostream>
#include <cstring>
using namespace std;

int const MAX_N = 10;

//输入
int n, m;
int w[MAX_N], v[MAX_N];
int times_1 = 0, times_2 = 0;

//Dfs
int Dfs(int i, int j){
    int res;
    if( i == n ){
        res = 0;
    }else if( j < w[i] ){
        res = Dfs( i + 1, j );
    }else{
        res = max( Dfs( i + 1, j ), Dfs( i + 1, j - w[i] ) + v[i] );
    }
    return res;
}

//记忆搜索
int f[MAX_N + 1][MAX_N + 1];
int rec(int i, int j){
    if( f[i][j] >= 0){
        return f[i][j];
    }

    if( i == n ){
        f[i][j] = 0;
    }else if( j < w[i] ){
        f[i][j] = rec( i + 1, j );
    }else{
        f[i][j] = max( rec( i + 1, j ), rec( i + 1, j - w[i] ) + v[i] );
    }
    return f[i][j];
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> w[i] >> v[i];
    cin >> m;

    cout << Dfs( 0, m ) << " times_1 = " << times_1 << endl;
    memset( f, -1, sizeof(f) );
    cout << rec( 0, m ) << " times_2 = " << times_2 << endl;
    
    return 0;
}