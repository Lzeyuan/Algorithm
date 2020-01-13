#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct{
	int x, y;
}point; 

void Bfs( point );

point p;
bool map[201][201] = {false};		//地图 
bool book[201][201] = {false};	//记录是否遍历过
int r, c;		//行列 
int count = 0;
queue<point> qq;

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
	
	for( int i = 1; i <= r; i++ )
	{	
		for( int j = 1; j <= c; j++)
		{
			//存在细胞且没遍历过 
			if( map[i][j] && !book[i][j] )
			{
				p.x = i;
				p.y = j;
				book[i][j] = true;		//记录遍历过 
				count++;		//细胞数+1 
				Bfs( p );		//广度优先搜索 
			}
		}
	}
	
	cout << count;
    return 0;
}

//右上左下 
int step[5] = { 0, 1, 0, -1, 0}; 

//广度优先搜索 
void Bfs( point p )
{
	qq.push(p);
	
	while( !qq.empty() )
	{
		point temp = qq.front();		//记录对头坐标 
		qq.pop();			//出队 
		
		//开始尝试 
		for( int k = 0; k <= 3; k++ )
		{
			int x = temp.x + step[k];
			int y = temp.y + step[k+1];
			
			//判断是否越界
			if( x < 1 || y < 1 || x > r || y > c )
				continue;
				
			//查找细胞 
			if( map[x][y] && !book[x][y] )
			{
				point t;
				t.x = x;
				t.y = y;
				qq.push(t);		//入队 
				book[x][y] = true;		//标记 
			}
		}
	}
}


