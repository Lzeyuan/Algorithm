#include <iostream>
#include <cstring>

using namespace std;

//范围
int const MAX_N = 500;
int const MAX_M = 10000;

//输入
int E, F;   //储蓄罐的初始和装满重量
int N;  //硬币的种类
int P;   //硬币价值
int W;   //硬币重量
int M;     //储蓄罐可以装 M Kg
int T;  //测试组数
int f[MAX_M];   //DP数组

int min(int x, int y) {
    return x > y ? y : x;
}

int main() {
    int n;
    while(~scanf("%d",&n))
	{
		while(n--)
		{
            cin >> E >> F;
            cin >> N;
            int D = F - E;
            
            for (int j = 1; j <= MAX_M; j++) {
                f[j] = 0x6fffffff;
            }

            f[0] = 0;

            for (int j = 1; j <= N; j++) {
                cin >> P >> W;
                for (int j = W; j <= D; j++) {
                    f[j] = min(f[j], f[j - W] + P);
                }
            }

            if (f[D] != 0x6fffffff)
                cout << "The minimum amount of money in the piggy-bank is " << f[D] << '.' << endl;
            else
                cout << "This is impossible." << endl;
        }
    }
    return 0;
}
