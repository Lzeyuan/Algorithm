#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main()
{
	int p1, p2, p3;
	char str[100];
	
	cin >> p1 >> p2 >> p3 >> str;
	
	int i = 0;
	
	while(str[i])
	{
		if(str[i] == '-')
		{
			if( isalpha(str[i-1]) && isalpha(str[i+1]) && str[i-1] < str[i+1] )
			{
				for(int k = (p3 == 1 ? str[i-1] + 1 : str[i+1] - 1); p3 == 1 ? k <= str[i+1] - 1 : k >= str[i-1] + 1; k += (p3 == 1 ? 1 : -1))
				{
					if(p1 == 1)
					{
						for(int l = 1; l <= p2; l++)
							cout << char(tolower(k));
					}
					else if(p1 == 2)
					{
						for(int l = 1; l <= p2; l++)
							cout << char(toupper(k));
					}
					else if(p1 == 3)
					{
						for(int l = 1; l <= p2; l++)
							cout << '*';
					}
				}
				i++;
			}
			else if( isdigit(str[i-1]) && isdigit(str[i+1]) && str[i-1] < str[i+1] )
			{
				for(int k = (p3 == 1 ? str[i-1] + 1 : str[i+1] - 1); p3 == 1 ? k <= str[i+1] - 1 : k >= str[i-1] + 1; k += (p3 == 1 ? 1 : -1))
				{
					if(p1 == 3)
					{
						for(int l = 1; l <= p2; l++)
							cout << '*';
					}
					else
					{
						for(int l = 1; l <= p2; l++)
							cout << k-48;
					}
				}
				i++;
			}
		}
		cout << str[i];
		i++;
	}
	
    return 0;
}



