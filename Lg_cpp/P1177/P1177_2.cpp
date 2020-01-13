#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <algorithm>

using namespace std;

void quickSort(int *a, int left, int right)
{
	int i, j;
	i = left;
	j = right;

	if (i >= j)
		return;

	int t;
	t = a[i];

	srand(time(NULL));
	int pviot = rand()%(j-i+1) + i;

	a[left] = a[pviot];
	a[pviot] = t;
	t = a[left];

	while (i < j)
	{
		while (i < j && t <= a[j])
			j--;
		while (i < j && t >= a[i])
			i++;
		
		swap(a[i], (i == j) ? a[left] : a[j]);
	}


	quickSort(a, left, i-1);
	quickSort(a, i + 1, right);
}

void quicksort(int *a, int x, int y)
{
	int i = x, j = y;
	int k = a[x];
	if (i >= j)
		return;
	while (i < j)
	{
		while (i<j && a[j]>k)
			j--;
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] <= k)
			i++;
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = k;
	quicksort(a, x, i - 1);
	quicksort(a, i + 1, y);
}

void qsort(int *a,int l, int r)//应用二分思想
{
	int mid = a[(l + r) / 2];//中间数
	int i = l, j = r;

	do {
		while (a[i] < mid) 
			i++;//查找左半部分比中间数大的数

		while (a[j] > mid) 
			j--;//查找右半部分比中间数小的数

		if (i <= j)//如果有一组不满足排序条件（左小右大）的数
		{
			swap(a[i], a[j]);//交换
			i++;
			j--;
		}
	} while (i <= j);//这里注意要有=

	if (l < j) 
		qsort(a, l, j);//递归搜索左半部分
	if (i < r)
		qsort(a, i, r);//递归搜索右半部分
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int i;
	int n, a[100001] = { 0 };
	cin >> n;

	for ( i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	//qsort(a, 1, n);
	sort(a+1,a+n+1);

	for (i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}

    return 0;
}
