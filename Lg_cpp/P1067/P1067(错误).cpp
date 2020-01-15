#include <iostream>

#define MAXSIZE 201 

using namespace std;

int  main()
{
	int n;
	cin >> n;
	
	int a[MAXSIZE];
	for(int i = n+1; i >= 1; i--)
	{
		cin >> a[i];
	}
	
	for (int i = n+1; i >= 1; i--)
	{
		if (a[i] != 0)
		{
			if (i != n+1)
			{
				if(i > 2)
				{
					if(a[i] == 1)
					{
						cout << '+' << "x^" << i-1 ;
					}
					else if (a[i] == -1)
					{
						cout << '-' << "x^" << i-1 ;
					}
					else if(a[i] > 0)
						cout << '+' << a[i] << "x^" << i-1 ;
					else
						cout << a[i] << "x^" << i-1 ;
				}
				else if( i == 2)
				{
					if(a[i] == 1)
					{
						cout << '+' << i-1 ;
					}
					else if (a[i] == -1)
					{
						cout << '-' << i-1 ;
					}
				}
				else
					cout << '+' << a[i];
			}
			else
			{
				cout << a[i] << "x^" << i-1;
			}				
		}
	}
	
	return 0;
}

