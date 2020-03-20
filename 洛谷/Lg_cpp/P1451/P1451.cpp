#include <iostream>
#include <cstdio>

using namespace std;

void Dfs( int row, int col );

bool map[201][201] = {false};		//地图 
bool book[201][201] = {false};	//记录是否遍历过
int r, c;		//行列 

int main()
{
	//输入行、列
	cin >> r >> c;
	
	//输入地图 
	for( int i = 1; i <= r; i++ )
		for( int j = 1; j <= c; j++ ) 
		{
			int loca;
			scanf("%1d", &loca);
			
			//大于0记录 
			if( loca > 0 )
				map[i][j] = true;
			else
				map[i][j] = false;
		}
	
	//开始遍历寻找细胞数
int count = 0;	//记录细胞数 
	for( int i = 1; i <= r; i++ )
		for( int j = 1; j <= c; j++ ) 
		{
			//存在细胞且没遍历过 
			if( map[i][j] && !book[i][j] )
			{
				book[i][j] = true;
				Dfs( i, j );
				count++;
			}
		}
	
	cout << count;
    return 0;
}

//右上左下 
int step[5] = { 0, 1, 0, -1, 0}; 
void Dfs( int row, int col )
{
	for( int i = 0; i <= 3; i++ )
	{
		int x = row + step[i];
		int y = col + step[i+1];
		
		//判断是否越界
		if( x < 1 || y < 1 || x > r || y > c )
			continue;
		
		//判断是否遍历过或是否可以是细胞的一部分 
		if( map[x][y] && !book[x][y] )
		{
			book[x][y] = true;
			Dfs( x, y );
		}
	} 
}


