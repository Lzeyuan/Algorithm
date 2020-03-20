//深度搜索 
#include <iostream> 
#include <cstring>
#include <cstdio>

using namespace std;

int dx, dy;
int book[21][21]={0};
int m = 0;

void dfs(int x, int y,int *sum)
{
	int next[2][2] = {{0,1},{1,0}};
	int tx, ty, k;
	//cout << "x = " << x << "  y = " << y << endl;
	if(x == dx && y == dy)
	{
		//cout << endl;
		(*sum) += 1;
		return;
	}
	
	for(k = 0; k < 2; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if(tx < 0 || ty < 0 || tx > dx || ty > dy)
			continue;
		
		if(book[tx][ty] == 1)
		{
			(*sum)++;
			continue;
		}
		
		if(book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx,ty,sum);
		}
	}
	return;
}

int main(void)
{
	int mx, my, inf = 99999;
	int i, k, sum = 0;
	
	cin >> dx >> dy >> mx >> my;
	
	memset(book, 127, sizeof(book));
	
	for(i = 0; i <= dx; i++)
		for(k = 0; k <= dy; k++)
			book[i][k] = 0;
	
	book[mx][my] = inf;
	book[mx-1][my+2] = inf;		//上下左右 
	book[mx+1][my+2] = inf;
	book[mx-1][my-2] = inf;
	book[mx+1][my-2] = inf;
	book[mx+2][my+1] = inf;
	book[mx+2][my-1] = inf;
	book[mx-2][my+1] = inf;
	book[mx-2][my-1] = inf;

	/*for(i = 0; i <= 6; i++)
	{
		for(k = 0; k <= 6; k++)
		{
			printf("%8d",book[i][k]);
		}
		cout << endl;
	}*/

	dfs(0,0,&sum);
	
	cout << sum;
	
    return 0;
}


