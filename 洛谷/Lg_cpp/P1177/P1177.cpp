#include <iostream>
#include <cstdio> 

using namespace std;

const int MAXSIZE = 100001;

void quickSort(int *a, int left, int right)
{
	int i, j, t;
	
	if(left > right)
		return;
	
	int temp = a[left];
	i = left;
	j = right;
	
	while(i != j)
	{
		while(i < j && temp <= a[j])
			j--;
			
		while(i < j && temp >= a[i])
			i++;
		
		if(i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t; 
		}
	}
	
	a[left] = a[i];
	a[i] = temp;

	quickSort(a, left, i-1);
	quickSort(a, i+1, right);

	return;
}

int main()
{
	int n, i;
	int a[MAXSIZE] = {0};
	
	cin >> n;
	
	for(i = 1 ; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	quickSort( a, 1, n);
	
	for(i = 1; i <= n; i++)
	{
		printf("%d ",a[i]);
	}
	
    return 0;
}



