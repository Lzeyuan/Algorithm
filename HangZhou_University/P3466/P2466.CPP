//HangZhou_University P2466
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int const MAX_P = 100;
int const MAX_Q = 100;
int const MAX_V = 1000;
int const MAX_N = 500;
int const MAX_M = 5000;
//input
int M, N;
typedef struct{
    int P, Q, V;
}Trade;

Trade trade[MAX_N];

//solve
int f[MAX_M + 1];
int solve(){
    memset(f, 0, sizeof(f));
    for( int i = 0; i < N; i++ ){
        for( int j = M; j >= trade[i].Q && j >= trade[i].P; j-- ){
                f[j] = max( f[j], f[ j - trade[i].P ] + trade[i].V );
        }
        for( int k = 0; k <= M; k++ ){
            printf("%5d", f[k]);
        }
        cout << endl;
    }  

    cout << f[M] << endl;

    return 0;
}

bool cmp( Trade x, Trade y ){
    return x.P - x.Q > y.P - y.Q;
}

int main(){
    while( ~scanf("%d %d", &N, &M) ){
        for( int i = 0; i < N; i++ ){
            cin >> trade[i].P >> trade[i].Q >> trade[i].V ;
        }
        
        sort(trade, trade + N, cmp);
        solve();
    }

    return 0;
}



/*
4 5 3
4 6 3
1 5 3
0 0 0 0 0 3 3 3 3 3
0 0 0 0 0 3 3 3 6 6
0 0 0 0 0 3 6 6 6 9
*/