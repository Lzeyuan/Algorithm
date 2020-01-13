/*
	该题为不知道答案到底有少层（n），因此只能用递归去尝试（dfs） 
*/ 

#include <iostream>
#include <cstdio>

using namespace std;

void dfs(int time, int n, int book[], int *a)
{
	if(time == 0)
	{
		for(int j = n; j >= 1; j--)
		{
			printf("%5d", a[j]);
		}
		printf("\n");
		return;
	}
	
	for(int i = 1; i <= n; i++)		//尝试 1~9 
	{
		if(!book[i])		//是否已经尝试 
		{
			book[i] = 1;
			a[time] = i;
			dfs(time - 1, n, book, a);
			book[i] = 0;		//回溯 
			a[time] -= i;
		}
	}
} 

int main()
{
	int n, book[10] = {0}, a[10] = {0};
	
	cin >> n;
	
	dfs(n, n, book, a);
	
    return 0;
}



