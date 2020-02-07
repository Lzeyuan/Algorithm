#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int const MAX_WEIGHT = 450;
int const MAX_VALUE = 100;
int const MAX_KNAPSACK = 700;
int const MAX_N = 100;

//输入
int w[MAX_WEIGHT], v[MAX_VALUE];
int n, weight;

//01递归
int rec1(int i, int j){
	int res;
	if ( i == n + 1 ) {		//此处是坑，如果输入是从1开始，则dp递归的终点要设置到n+1
		res = 0;
	}
	else if ( j < w[i] ) {
		res = rec1( i + 1, j );
	}
	else {
		res = max( rec1( i + 1, j ), rec1( i + 1, j - w[i] ) + v[i] );
	}
	return res;
}

//02时间优化递归（一开始要初始化数组为-1）
int dp[MAX_N + 2][MAX_KNAPSACK + 1];		//输入从1开始则 MAX_N 需要+2，第一行作废
int rec2(int i, int j) {
	if( dp[i][j] >= 0 ){
		return dp[i][j];
	}

	int res;
	if ( i == n + 1 ) {		//此处是坑，如果输入是从1开始，则dp递归的终点要设置到n+1
		res = 0;			//因为，以n为终点，第n个数据没有判断就直接返回0了
	} else if ( j < w[i] ) {
		res = rec2( i + 1, j );
	} else {
		res = max( rec2(i + 1, j), rec2( i + 1, j - w[i] ) + v[i] );
	}
	return dp[i][j] = res;
}

//03循环（正序）
int dp3[MAX_N + 2][MAX_KNAPSACK + 1];		//输入从1开始则 MAX_N 需要+2，第一行作废
int rec3(int j) {
	for ( int i = 1; i <= n; i++ ) {
		for ( int k = j; k >= 0; k-- ) {
			if( k < w[i] ){
				dp3[i + 1][k] = dp3[i][k];
			} else {
				dp3[i + 1][k] = max( dp3[i][k], dp3[i][ k - w[i] ] + v[i] );
			}
		}
	}
	return dp3[n + 1][j];
}

//04空间+时间优化循环（一定要从尾开始判断）
int f_space[MAX_N + 1];
int rec4(int j) {
	for (int i = 1; i <= n; i++) {
		for (int k = j; k >= w[i] ; k--) {		//可以将循环判断改成 max( sum(v[i],...,v[n]), w[i] )，但是当物品价值远大于重量就没有意义了
			f_space[k] = max( f_space[k], f_space[ k - w[i] ] + v[i] );
		}
	}
	return f_space[j];
}

int main(){
	cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		cin >> w[i] >> v[i];
	}
	cin >> weight;
	memset( dp, -1, sizeof(dp) );
	cout << "rec1：" << rec1( 0, weight ) << endl;
	cout << "rec2：" << rec2( 1, weight ) << endl;
	cout << "rec3：" << rec3( weight ) << endl;
	cout << "rec4：" << rec4( weight ) << endl;

	system("pause");
    return 0;
}

/*
测试数据：
数据一：
4
2 3 
1 2 
3 4 
2 2
5
输出：7
数据二：
4
1 4
2 6
3 12
2 7
6
输出：23
数据三：
3
3 1
2 2
1 3
5
输出：5
数据四：
3
100 2
300 5
450 9
700
输出：11
*/