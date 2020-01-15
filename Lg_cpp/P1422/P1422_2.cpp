#include  <iostream>

using namespace std;

int main()
{
	double n;
	double sum = 0;
	
	cin >> n;
	
	if (n <= 150)
	{
		sum = n*0.4463;
	}
	if (151 <= n && n <=400)
	{
		sum = 150*0.4463 + (n-150)*0.4663;
	}
	if (n >= 401)
	{
		sum = 150*0.4463 + (400 - 150)*0.4663 + (n - 400)*0.5663;
	}
	sum = int(sum*10 + 0.5)/10.0;
	cout << sum;
    return 0;
}

