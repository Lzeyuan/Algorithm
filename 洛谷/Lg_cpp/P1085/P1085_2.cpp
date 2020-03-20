#include  <iostream>

using namespace std;

int main()
{
	int i, a, b, max = 0, f = 0;
	
	for(i = 1; i <= 7; i++)
	{
		cin >> a >> b;
		if (max < a+b)
		{
			max = a+b;
			f = i;
		}
	}
	if (max <= 8)
		f = 0;
	cout << f;
    return 0;
}

