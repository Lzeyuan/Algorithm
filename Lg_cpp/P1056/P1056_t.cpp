#include  <iostream>

using namespace std;

void min(int &a, int &b)
{
	if(a > b)
	{
		int t = a;
		a = b;
		b = t;
	}
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
			min(y1,q);
			y[y1] = t;
			sy++;
		}
		else if (y1 == q)
		{
			min(x1,p);
			x[x1] = t;
			sx++;
		}
	}
	
	for(i = 1; i <= m && sx; i++)
	{
		if(x[i] != 0)
		{
			if (sx-1)
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
