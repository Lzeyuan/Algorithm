#include <iostream>

using namespace std;

const int MAXSIZE = 1001;


int main()
{
	int n, book[MAXSIZE] = { 0 };
	int sum = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		if (!book[t])
		{
			book[t] = 1;
			sum++;
		}
	}
	
	cout << sum << endl;
	for (int k = 1; k <= MAXSIZE - 1; k++)
	{
		if (book[k])
			cout << k << ' ';
	}

	return 0;
}


