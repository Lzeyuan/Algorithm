#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int n, a[100000] = {0};
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i >= 2 && a[i] > a[i-1])
		{
			int j = i-2;
			while(a[i-1] == a[j])
			{
				j--;
			}
			if(a[i-1] < a[j])
				sum++;
		}
	}
	
	cout << sum;
	
    return 0;
}



