#include <iostream>
#include <cstdio>

using namespace std;

int const MAX_H = 5000;
int const MAX_C = 50000;

//输入
int c, h;
int v_i[MAX_H + 1];

//01背包问题
int f[MAX_C + 1];
int knapsack(){
    for( int i = 1; i <= h; i++ ){
        for( int j = c; j >= v_i[i]; j-- ){
            f[j] = max( f[j], f[j - v_i[i]] + v_i[i] );
        }
        /*for( int j = 0; j <= c; j++ ){
            printf("%5d", f[j]);
        }
        cout << endl;*/
    }
    return f[c];
}

int main(){
    //输入
    cin >> c >> h;
    for( int i = 1; i <= h; i++ ){
        cin >> v_i[i];
    }

    cout << knapsack();

    return 0;
}