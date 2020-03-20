#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

typedef struct{
	int boom;
	int a[21];
}*worker,work;

work dfs(int road[21][21],int  start,int n,int const *w, worker book)
{
	work t;
	int max = 0;
	for(int i = 1; i <= n - start; i++)
	{
		if(road[start][i])
		{
			t = dfs(road, i+1, n, w, book);
			if(t.boom > max)
			{
				max = t.boom;
			}
		} 
	}
	
	if(book->boom < max)
	{
		book->boom = max;
		book->a[xz] = start;
	}
	return t;
}

int main()
{
	int n, j;
	worker wk;
	int w[21] = {0}, road[21][21] = {0};		//w记录每个地窖的地雷数，road记录每个地窖的通路

	cin >> n;
	cin.sync();
	
	j = 1;
	char c;
	for(int i = 1; i <= n; i++)			//读地雷数 
	{
		cin >> w[i];
	}
	c = getchar();
	for(int i = 1; i < n; i++)			//读取路径 
	{
		j = 1;
		while((c = getchar()) != '\n')
		{
			if(isdigit(c))
			{
				road[i][j++] = c - '0';
			}
		}
	} 
	
	int max = 0;
	work t;
	work book;
	for(int i = 1; i <= n; i++)			//尝试每个入口 
	{
		t = dfs(road, i, n, w, &book);
		if(t.boom > max)
			max = t.boom;
	}
	
    return 0;
}



