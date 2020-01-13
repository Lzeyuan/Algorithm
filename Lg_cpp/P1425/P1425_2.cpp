#include  <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	int hour, min;
	cin >> a >> b >> c >> d;
	hour = c - a;
	min = d - b;
	if(min < 0)
	{
		hour--;
		min += 60;
	}
	
	cout << hour << ' ' << min; 
	
    return 0;
}

