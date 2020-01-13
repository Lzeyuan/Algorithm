#include <iostream>

using namespace std;

int main()
{
	char c;
	int sum = 0;
	
	for(int i = 1; i<= 8; i++)
	{
		cin >> c;
		if(c == '1')
			sum++;
	}
	
	cout << sum;
	
    return 0;
}



