#include <iostream>

#define MAXSIZE 201 

using namespace std;

int  main()
{
	int n;
	cin >> n;
	
	int a[MAXSIZE];
	for(int i = n; i >= 0; i--)
	{
		cin >> a[i];
	}
	
	
	
	for (int i = n; i >= 0; i--)
	{
		if(a[i] != 0)
		{
			if(a[i] > 0 && i != n)
			{
				cout << '+';
			}
			
			if(a[i] == -1 && i != 0)
				cout << '-';
			
			if(a[i] != 1 && a[i] != -1 || i == 0)
				cout << a[i];
			
			if(i > 1)
			{
				cout << "x^" << i;
			}
			else if(i == 1)
			{
				cout << "x";
			}
		}
	}
	
	return 0;
}

