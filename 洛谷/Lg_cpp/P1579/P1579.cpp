#include<iostream>
#include<cmath>

using namespace std;

int PrimeNumber(int x)
{
	int i, j, y;
	
	y = sqrt(x);
	for(i = 2; i <= y;i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 2; i < 20000; i++ )
	{
		if(!PrimeNumber(i))
			continue;
		for(int j = 2; j < 20000; j++)
		{
			if(!PrimeNumber(j))
				continue;
			if( n - i - j > 0 && PrimeNumber(n-i-j))
			{
				cout << i << ' ' << j << ' ' << n-i-j <<endl;
				return 0;
			}
		}
	}
				
	return 0;
} 
