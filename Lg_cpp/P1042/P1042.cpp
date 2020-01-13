#include <iostream>

#define MAXSIZE 5682

using namespace std;

int book_11[MAXSIZE] = {0}, book_12[MAXSIZE] = {0};
int book_21[MAXSIZE] = {0}, book_22[MAXSIZE] = {0};

int main()
{
	int n, i, j1, j2;
	int x1, y1, x2, y2, s1 = 0, s2 = 0;
	char t;
	j1 = 1, j2 = 1;
	
	x1 = 0, y1 = 0;
	x2 = 0, y2 = 0;
	
	while(cin >> t)
	{
		if(t == 'W')
		{
			x1++;
			x2++;
		}
		else if(t == 'L')
		{
			y1++;
			y2++;
		}
		else if(t == 'E')
		{
			break;
		}
		
		if(x1 - y1 >= 2 && x1 >= 11 || y1 - x1 >= 2 && y1 >= 11)
		{
			book_11[j1] = x1;
			book_12[j1] = y1;
			x1 = 0, y1 = 0;
			s1++;
			j1++;
		}
		
		if(x2 - y2 >= 2 && x2 >= 21 || y2 - x2 >= 2 && y2 >= 21)
		{
			book_21[j2] = x2;
			book_22[j2] = y2;
			x2 = 0, y2 = 0;
			s2++;
			j2++;
		}
	}
	
	for(i = 1; i <= s1; i++)
		cout << book_11[i] << ":" << book_12[i] << endl;
	cout << x1 << ":" << y1 << endl;
		
	cout << endl;
	
	for(i = 1; i <= s2; i++)
		cout << book_21[i] << ":" << book_22[i] << endl;
	cout << x2 << ":" << y2 << endl;
	
    return 0;
}



