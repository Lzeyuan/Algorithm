#include <iostream>
#include <cstring> 
#include <time.h>
using namespace std;

int const MAX_N = 10;

//���� 
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

int rec(int i, int j){
	if( dp[i][j] >= 0 ){
		//��������Ļ�ֱ��ʹ��֮ǰ�Ľ��
		return dp[i][j]; 
	}
	int res;
	if( i == n ){
		res = 0;
	}else if( j < w[i] ){
		res = rec( i + 1, j );
	}else{
		res = max( rec( i + 1, j ), rec( i + 1, j - w[i] ) + v[i] );
	}
	//�������¼��������
	return dp[i][j] = res; 
} 

int main()
{
	cin >> n;
	for( int i = 1; i <= n; i++ )
		 cin >> w[i] >> v[i];
	cin >> W;
	
	time_t begin_t  = clock();
	memset( dp, -1, sizeof( dp ) );
	cout << "Max worth��" << rec( 0, W ) << endl;
	time_t finish_t = clock();
	cout<< "It cost " << (double )(finish_t - begin_t )
		<<" ms"<<endl;
    return 0;
}

/*
�������ݣ� 
	4
	2 3 1 2 3 4 2 2
	5 
*/
