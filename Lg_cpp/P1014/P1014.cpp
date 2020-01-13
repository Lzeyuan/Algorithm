#include <iostream>

using namespace std;

long long sum( long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long n;
	long long i=1,j=2,flag = 0;
	
	cin >> n;
	
	while(1)
	{
		if(n <= sum(i) )
		{
			flag = i;
			break;
		}
		else if(n <= sum(i+1))
		{
			flag = i+1;
			break;
		}
		i++;
	}

	j = n - sum(flag - 1);

	if(flag%2 == 0)
		cout << j << "/" << flag - j + 1 << endl;
	else
		cout << flag - j + 1 << "/"  << j << endl;
	
	return 0;
}
