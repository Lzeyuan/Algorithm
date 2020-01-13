#include <iostream>
#include <cstdio>

using namespace std;

int a[11] = {0,1,2,3,4,5,6,7,8,9};
int b[11] = {0};
int book[11] = {0};

void dsf(const int *a, int *b, int n, int *book, int k){
	int m = 0;
	
	if(k > n)
	{
		for(int j = 1; j <= n; j++)
			printf("%5d",b[j]);
		cout << endl;
		return;
	}
	
	for(m = 1; m <= n; m++)
	{
		if(book[m] != 0)
			continue;
		b[k] += a[m];
		book[m] = 1;
		dsf(a, b, n, book, k+1);
		b[k] -= a[m];
		book[m] = 0;
	}
	
} 

int main()
{
	int n;
	
	cin >> n;
	
	dsf(a, b, n, book, 1);
	
    return 0;
}



