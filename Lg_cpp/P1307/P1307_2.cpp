#include  <iostream>

using namespace std;

int main()
{
	long long a = 0, n;
	cin >> n;
	while(n)
	{
		a = a*10 + n%10;
		n = n/10;
	}
	
	cout << a;
	
    return 0;
}

