#include <iostream>

using namespace std;

int const MAX_N = 10;

//���� 
int n, W;
int w[MAX_N], v[MAX_N];

//�ӵ�i����Ʒ��ʼ��ѡ����С��j����
int rec(int i, int j){
	int res;
	if( i == n ){
	//û��ʣ��ĸ��� 
		res = 0;
	}else if( j < w[i] ){
		//�޷���ѡ�����Ʒ 
		res = rec(i + 1, j);
	}else{
		//��ѡ�Ͳ���ѡ���������������һ��
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
�������ݣ� 
4
2 3 1 2 3 4 2 2
5 
�����
7
*/
