#include <iostream>

using namespace std;
const int MAXSIZE = 6+1;

bool a[MAXSIZE][MAXSIZE] = {0},  book[MAXSIZE][MAXSIZE] = {0};

int total = 0;
int n, m;
int T;
int tarx, tary;

int next1[4][2] = { {1, 0},		//向右走 
				   {0, 1}, 		//向上走 
					{-1, 0},	//向左走 
					{0, -1}};	//向下走 

void dfs(int startx, int starty)
{
	/*
	* 注意！！这里一定要进入下一次栈里判断，而不是在尝试上下左右里判断
	* 因为有可能下往前走可以到目的地，而向左走也可以，只是路程不同！！ 
	*/ 
	
	//判断是否到达目的地 
	if( startx == tarx && tary == starty )
	{
		total++;
		return;
	} 
	
	for(int i = 0; i <= 3 ; i++)
	{
		int tx = startx + next1[i][0];
		int ty = starty + next1[i][1];
		
		//判断是否已经走过||有障碍物
		if( a[tx][ty] || book[tx][ty] ) 
			continue;
			
		//判断是否越界
		if(tx > m || ty > n || tx < 1 || ty < 1)
			continue;
		

		book[tx][ty] = true;
		dfs(tx, ty);		//看上面开头的注释！ 
		book[tx][ty] = false;
	}
}

int main()
{
	int startx, starty;
	
	cin >> n >> m >> T;
	
	cin >> startx >> starty;
	book[startx][starty] = true;
	
	cin >> tarx >> tary;
	
	for(int i = 1; i <= T; i++)
	{
		int tx, ty;
		cin >> tx >> ty;
		a[tx][ty] = true;
	} 
	
	dfs(startx, starty);
	
	cout << total; 
	
	cin.get();cin.get();

    return 0;
}

