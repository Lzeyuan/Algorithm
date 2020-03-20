#include <iostream>

using namespace std;

int main()
{
	long int book[2000001] = {0};
	
	int n, i, max = -999999;
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		int t;
		double f;
		cin >> f >> t;
		if(max < int(f*t))
		{
			max = int(f*t);
		}
		
		for(int j = 1; j <= t; j++)
		{
			if(!book[int(j*f)])
			{
				book[int(j*f)] = 1;
			}
			else
			{
				book[int(j*f)] = 0;
			}
		}	
	}
	
	for(i = 1; i <= max; i++)
		if(book[i])
		{
			cout << i;
			break;
		}
	
    return 0;
}



