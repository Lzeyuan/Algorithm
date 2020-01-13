#include <iostream>

using namespace std;

int main()
{
	int n, k;
	double sum = 0;
	
	cin >> k;
	n = 1;
	
	while(sum <= k)
	{
		sum += 1.0/n;
		n++;
	}
	
	cout << n-1 << endl;
	
    return 0;
}



