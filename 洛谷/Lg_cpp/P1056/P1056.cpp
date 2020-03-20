#include  <iostream>

using namespace std;

int main()
{
	int m, n, k , l, d;
	int x[1000]={0}, y[1000]={0};
	int x1, y1, p, q;
	int t, i;
	
	cin >> m >> n >> k >> l >> d;
	
	for(int i = 0; i < d; i++)
	{
		cin >> x1 >> y1 >> p >> q;
		if (x1 == p)
		{
			t = y1 > q ? y1:q;
			y1 = y1 < q ? y1:q; 
			y[y1] = t;
		}
		else if (y1 == q)
		{
			t = x1 > p ? x1:p;
			x1 = x1 < p ? x1:p;
			x[x1] = t;
		}
	}
	
	for(i = 0; i < m-1; i++)
	{
		if(x[i] != 0)
		{
			cout << i << ' '; 
		}
	}
	
	if(x[i] != 0)
	{
		cout << i; 
	}
	cout << endl;
	
	for(i = 0; i < n-1; i++)
	{
		if(y[i] != 0)
		{
			cout << i << ' '; 
		}
	}
	
	if(y[i] != 0)
	{
		cout << i; 
	}
	return 0;
}
