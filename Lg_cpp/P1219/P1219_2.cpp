#include <iostream>

using namespace std; 

const int MAXSIZE = 27;

int a[MAXSIZE] = {0};		//记录行 
int b[MAXSIZE] = {0};		//记录列 
int c[MAXSIZE] = {0};		//记录左上到右下 
int d[MAXSIZE] = {0};		//记录右上到左下 
int total = 0;		//记录总共有多少种情况 

int queen(int n, int column)
{
	if(column > n)
	{
		if(total <= 2)
		{
			for(int j = 1; j <= n; j++)
				cout << a[j] << " ";
			cout << endl; 
		}
		total++;
		return 0;
	}
	
	for(int i = 1; i <= n ; i++)		//遍历每一种情况 
	{
		if(!a[column] && !b[i] && !c[column + i] && !d[n - column + i])		//判断是否之前是否已经加入 
		{	
			a[column] = i;
			b[i] = 1;
			c[column + i] = 1;
			d[n - column + i] = 1;
			queen(n, column+1);
			a[column] = 0;
			b[i] = 0;
			c[column + i] = 0;
			d[n - column + i] = 0;
		}
		
	}
}

int main()
{

	int n;
	
	cin >> n;
	
	queen(n,1);
	
	cout << total; 
	
    return 0;
}



