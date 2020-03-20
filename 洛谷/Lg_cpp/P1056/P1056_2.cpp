#include  <iostream>

using namespace std;

int min(int a, int b)
{
	return a<b ? a:b;	
}

int main()
{
	int m, n, k , l, d;
	int x[1001]={0}, y[1001]={0};
	int x1, y1, p, q;
	int t, i, sx = 0, sy = 0;
	
	cin >> m >> n >> k >> l >> d;
	
	for(i = 1; i <= d; i++)
	{
		cin >> x1 >> y1 >> p >> q;
		if (x1 == p)
		{
			if (y[min(y1,q)] == 0)
				sy++;
			y[min(y1,q)]++;
		}
		else if (y1 == q)
		{
			if (x[min(x1,p)] == 0)
				sx++;
			x[min(x1,p)]++;
		}
	}
	
	while (sx > k)
	{
		int min = 99999, f;
		for (int j = 1; j < m; j++)
		{
			if (x[j] != 0 && min > x[j])
			{
				min = x[j];
				f = j;
			}
		}
		x[f] = 0;
		sx--;
	}

	while (sy > l)
	{
		int min = 99999, f;
		for (int j = 1; j < n; j++)
		{
			if (y[j] != 0 && min > y[j])
			{
				min = y[j];
				f = j;
			}
		} 
		y[f] = 0;
		sy--;
	}

	for(i = 1; i < m && sx; i++)
	{
		if(x[i] != 0)
		{
			if (sx - 1)
			{
				cout << i << ' '; 
			}
			else
			{
				cout << i;
			}
			sx--;
		}
	}
	
	cout << endl;
	
	for(i = 1; i <= n && sy; i++)
	{
		if(y[i] != 0)
		{
			if(sy - 1)
			{
				cout << i << ' '; 
			}
			else
			{
				cout << i;
			}
			sy--;
		}
	}
	
	return 0;
} 
