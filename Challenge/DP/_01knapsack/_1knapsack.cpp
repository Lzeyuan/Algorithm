#include <iostream>

using namespace std;

int const MAX_N = 10;

//输入 
int n, W;
int w[MAX_N], v[MAX_N];

//从第i个物品开始挑选总重小于j部分
int rec(int i, int j){
	int res;
	if( i == n ){
	//没有剩余的格子 
		res = 0;
	}else if( j < w[i] ){
		//无法挑选这个物品 
		res = rec(i + 1, j);
	}else{
		//挑选和不挑选的两种情况都尝试一下
		res = max( rec(i + 1, j), rec( i + 1, j - w[i] ) + v[i] );
	}
	return res;
} 

int main()
{
	cin >> n;
	for( int i = 0; i < n; i++ )
		 cin >> w[i] >> v[i];
	cin >> W;
	
	cout << rec( 0, W ); 
    return 0;
}

/*
测试数据： 
4
2 3 1 2 3 4 2 2
5 
输出：
7
*/
