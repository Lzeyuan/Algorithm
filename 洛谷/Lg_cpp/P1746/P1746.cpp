#include <iostream>

using namespace std;

int const SIZE = 1000;

int map[SIZE][SIZE] = {false};
int n;
int ans = 0x7fffffff;
int startx, starty;
int tarx, tary;


//上右左下 
int sp[5] = {0, 1, 0, -1, 0};

void Dfs(int r, int c, int step)
{
	if( r == tarx && c == tary )
	{
		if( step < ans )
			ans = step;
		return;
	}
	
	int x, y;
	for( int i = 0; i <= 3; i++ )
	{
		x = r + sp[i];
		y = c + sp[i + 1];
		
		//判断越界 
		if( x < 0 || y < 0 || x > n || y > n )
			continue;
		
		//
		if( !map[x][y] ) 
		{
			map[x][y] = 1;
			Dfs( x, y, step + 1 );
			map[x][y] = 0;
		}
		
	}
} 

int main()
{
	cin >> n;
	
	char t[SIZE];
	for( int i = 0; i < n ; i++ )
	{
		cin >> t;
		for( int j = 0; j < n; j++ )
		{
			map[i][j] = t[j] - 48;
		}
	}
	
	
	cin >> startx >> starty;
	cin >> tarx >> tary;	
	
	Dfs( startx, starty, 0 );
	
	cout << ans;	
	
	return 0;
}

