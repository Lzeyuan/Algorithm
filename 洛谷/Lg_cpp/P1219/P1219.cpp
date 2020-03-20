#include <iostream>

using namespace std;

const int MAXSIZE = 100;

int a[MAXSIZE] = {0}, b[MAXSIZE] = {0}, c[MAXSIZE] = {0}, d[MAXSIZE] = {0};
int n;
int total;

int print()
{
	if(total <= 2)
	{
		for(int k = 1; k <= n; k++)
			cout << a[k] << " ";
		cout << endl;
	}
	total++;
}

void queen(int i)
{
	if(i > n)
	{
		print();
		return;
	}
	else
	{
		for(int j = 1; j <= n; j++)
		{
			if(!b[j] && !c[i+j] && !d[n-j+i])
			{
				a[i] = j;
				b[j] = 1;
				c[i+j] = 1;
				d[n-j+i] = 1;
				queen(i+1);
				//====»ØËÝ==== 
				b[j] = 0;
				c[i+j] = 0;
				d[n-j+i] = 0;
			}
		}
	}
	
}

int main()
{
	cin >> n;
	queen(1);
	cout << total; 
	
    return 0;
}



