#include <iostream>

using namespace std;

int const MAXSIZE = 21;
int SIZE_A = 13440;
int SIZE_B = 10000;
int SIZE_C = 64;
int SIZE_ST = 100;
int MAX_SELL = 1000000; 

int m, n;
int a[SIZE_A], b[SIZE_B], c[SIZE_C], st[SIZE_ST];

int main()
{
	cin >> m >> n;
	
	for( int i = 1; i <= n; i++ )
		cin << a[i] << b[i] << c[i] << st[i];
	
	
	
	return 0;
}

