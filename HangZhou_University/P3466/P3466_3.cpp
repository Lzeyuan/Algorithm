//HangZhou_University P2466
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//范围
int const MAX_N = 5E2;    //最大物品种数
int const MAX_M = 5E3;    //最大起始资金

//输入
int N;  //物品种数
int M;  //起始资金


//物品
typedef struct {
    int P;   //售价
    int Q;   //歧视价
    int V;   //价值
}Object;
Object object[MAX_N + 1];

//01背包问题
int dp[MAX_M + 1];
void ZeroOnePack() {
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= object[i].Q && j >= object[i].P; j--) {
            dp[j] = max(dp[j], dp[j - object[i].P] + object[i].V);
        }
    }
}

//紧迫度
int Compare(Object ob1, Object ob2) {
    int d1 = ob1.P - ob1.Q;
    int d2 = ob2.P - ob2.Q;
    if (d1 > d2) {
        return 1;
    } else if (d1 < d2) {
        return 0;
    } else {
        return 2;
    }
}

//快排

//紧迫度
bool cmp( Object x, Object y ){
    return x.P - x.Q > y.P - y.Q;
}

int main() {
    while (cin >> N >> M) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++) {
            cin >> object[i].P >> object[i].Q >> object[i].V;
        }
        sort(object + 1, object + N + 1, cmp);
        ZeroOnePack();
        
        cout << dp[M] << endl;
    }
    return 0;
}