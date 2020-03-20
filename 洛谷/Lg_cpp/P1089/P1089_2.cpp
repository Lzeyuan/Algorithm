#include  <iostream>

using namespace std;

int main()
{
	int n, a, b, i, sum = 0, min = 999999999;
	
	cin >> n;
	for(i = 1; i <= 3; i++)
	{
		cin >> a >> b;
		sum = n/a; 
		if (n%a)
			sum++;
		sum *= b;
		min = min <= sum ? min : sum;
	}
	
	cout << min;
	
    return 0;
}

