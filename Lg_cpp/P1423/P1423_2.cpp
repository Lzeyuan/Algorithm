#include <iostream>

using namespace std;

int main()
{
	long double s, d, l;
	int n;
	
	cin >> d;
	s = 0;
	l = 2;
	
	while(s < d)
	{
		s += l;
		l *=  0.98;
		n++;
	}
	
	cout << n;
    return 0;
}



