#include <iostream>
#include <cmath>

using namespace std;

void fun(int n)
{
	int i;

	if(n == 0)
	{
		cout << "0";
		return;
	}
	
	for(i = 0; pow(2,i) - n < 0; i++);

	
	if(pow(2,i) == n)
	{
		if(i == 1)
		{
			cout << "2";
			return;
		}
		cout << "2(";
		fun(i);
		cout << ")";
	}
	else if(pow(2,i) > n)
	{
		i--;
	
		if(i == 1)
		{
			cout << "2+";	
		}
		else
		{
			
			cout << "2(";
			fun(i);
			cout << ")+";
		}
		n -= pow(2,i);
		
		fun(n);
	}
}


int main()
{
	int n, i, j = 0, k, c[20] = {0};
	
	cin >> n;

	while(n)
	{
		for(i = 0; pow(2,i) - n < 0; i++);
		if(pow(2,i) - n != 0)
			i--;
		
	//	cout << '\n' << pow(2,i) << ' ' << n <<endl;
		
		if(i == 1)
		{
			cout << "2";
		}
		else
		{
		
			cout << "2(";
			fun(i);
			cout << ")";
		}
		n -= pow(2,i);
		if(n)
			cout << '+';
	}	
	
    return 0;
}



