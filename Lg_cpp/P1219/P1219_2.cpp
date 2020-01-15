#include <iostream>

using namespace std; 

const int MAXSIZE = 27;

int a[MAXSIZE] = {0};		//��¼�� 
int b[MAXSIZE] = {0};		//��¼�� 
int c[MAXSIZE] = {0};		//��¼���ϵ����� 
int d[MAXSIZE] = {0};		//��¼���ϵ����� 
int total = 0;		//��¼�ܹ��ж�������� 

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
	
	for(int i = 1; i <= n ; i++)		//����ÿһ����� 
	{
		if(!a[column] && !b[i] && !c[column + i] && !d[n - column + i])		//�ж��Ƿ�֮ǰ�Ƿ��Ѿ����� 
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



