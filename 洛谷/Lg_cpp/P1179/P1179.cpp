#include <iostream>

using namespace std;

int main()
{
	int n, m, sum = 0;
	
	cin >> n >> m;
	
	for(int i = n; i <= m; i++)
	{
		int t = i;
		while(t)
		{
			if(t%10 == 2)
			{
				sum++;
			}
			t /= 10;
		}
	}
	
	cout << sum;
	 
    return 0;
}



