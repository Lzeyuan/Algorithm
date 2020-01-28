#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int const MAX_WEIGHT = 100;
int const MAX_VALUE = 100;
int const MAX_KNAPSACK = 100;
int const MAX_N = 100;

//输入
int w[MAX_WEIGHT], v[MAX_VALUE];
int n, weight;

//01递归
int rec1(int i, int j){
	int res;
	if ( i == n ) {
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

//02时间优化递归
int f[MAX_N + 1][MAX_KNAPSACK + 1];
int rec2(int i, int j) {
	int res;
	if (i == n) {
		res = 0;
	}
	else if (j < w[i]) {
		res = rec2(i + 1, j);
	}
	else {
		res = max(rec2(i + 1, j), rec2(i + 1, j - w[i]) + v[i]);
	}
	return f[i][j] = res;
}

//03空间+时间优化递归
int f_space[MAX_N + 1];
int rec3(int j) {
	for (int i = 1; i <= n; i++) {
		for (int k = j; k >= w[i] ; k--) {
			f_space[k] = max( f_space[k], f_space[k - w[i]] + v[i] );

			//查看每次变化
			for( int m = 0; m <= j; m++ ){
				cout << f_space[m];
			}
			printf(" i = %d, k = %d\n", i, k);
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

	cout << "rec1：" << rec1( 0, weight ) << endl;
	cout << "rec2：" << rec2( 0, weight ) << endl;
	cout << "rec3：" << rec3( weight ) << endl;

	system("pause");
    return 0;
}

/*
测试数据：
4
2 3 
1 2 
3 4 
2 2
5
输出：
7
*/