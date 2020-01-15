#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int zf = 0, cf = 0;
	int i, sum = 0;
	
	cin >> n >> m;
	
	for(i = 1; i <= m; i++)
	{
		for(int j = 1; j <=n ; j++)
		{
			int t = (m-i+1)*(n-j+1);
			if(i == j)
			{
				zf += t;
			} 
			else
			{
				cf += t;
			}
		}
	}
	
	cout << zf << ' ' << cf;
	
    return 0;
}



