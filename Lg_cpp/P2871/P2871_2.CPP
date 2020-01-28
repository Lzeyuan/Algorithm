#include <iostream>
#include <cstdio>

using namespace std;

int const MAX_WI = 400; 
int const MAX_DI = 100;
int const MAX_N = 3402;
int const MAX_M = 12880;

//ÊäÈë
int n, m;
int Wi[MAX_WI] , Di[MAX_DI];
int dp[MAX_N + 1][MAX_M + 1];

int main()
{
	cin >> n >> m;
	for( int i = 0; i < n; i++ )
		cin >> Wi[i] >> Di[i];
	
	for( int i = n - 1; i >= 0; i-- ){
		for( int j = 0; j <= m ; j++ ){
			if( j < Wi[i] ){
				dp[i][j] = dp[i + 1][j];
			}else{
				dp[i][j] = max( dp[i + 1][j], dp[i + 1][j - Wi[i]] + Di[i] );
			}
		}
	}
	
	/*
	for( int i = 0; i <= n; i++ ){
		for( int j = 0; j <= m ; j++ ){
			printf("%5d ", dp[i][j]);
		}
		cout << endl;
	}
	*/
	
	cout << dp[0][m];
	
	return 0;
}


/*
²âÊÔÊý¾Ý£º
	4 5
	2 3
	1 2
	3 4
	2 2 
*/
