#include  <iostream>

using namespace std;

int main()
{
	int m, n, t, time = 0;
	int *a, front = 0, tail = 0;
	
	cin >> m >> n;
	
	if (m == 0)
	{
		cout << time;
		return 0;
	}
	
	//创建循环队列 
	a = new int[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = -99999;
	}
	
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		cin >> t;
		for (int j = 0 ; j < m; j++)
		{
			if (a[j] == t)
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 0)
		{
			if (a[tail] == -99999 && tail == front)
			{
				a[tail] = t;
				time++;
				continue;
			}
			
			if((tail+1)%m != front)
			{
				tail = (tail+1)%m;
				a[tail] = t;
			}
			else
			{
				front = (front+1)%m;
				tail = (tail+1)%m;
				a[tail] = t;
			}
			
			time++;
		}
	}
	
	cout << time;
	
	return 0;
}
