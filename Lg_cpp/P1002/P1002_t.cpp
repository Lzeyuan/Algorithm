#include <iostream>
#define MAXSZIE 40

using namespace std;

int main()
{
	unsigned long long sum[MAXSZIE][MAXSZIE] = {0};
	bool s[MAXSZIE][MAXSZIE];
	int mx, my, dx, dy, inf = 1;
	int i, k;
	
	cin >> dx >> dy >> mx >> my;
	
	dx++, dy++, mx++, my++;
	
	sum[1][0] = 1;
	
	s[mx][my] = inf;
	s[mx-1][my+2] = inf;		//иообвСср 
	s[mx+1][my+2] = inf;
	s[mx-1][my-2] = inf;
	s[mx+1][my-2] = inf;
	s[mx+2][my+1] = inf;
	s[mx+2][my-1] = inf;
	s[mx-2][my+1] = inf;
	s[mx-2][my-1] = inf;
	
	for(i = 1; i <= dx; i++)
	{	
		for(k = 1; k <= dy; k++)
		{
			if(s[i][k])
			{
				continue;
			}
			sum[i][k] = sum[i][k] < (sum[i-1][k] + sum[i][k-1]) ? (sum[i-1][k] + sum[i][k-1]) : sum[i][k];
		}
	}

	
	cout << sum[dx][dy];
	
    return 0;
}



