#include <iostream>
#include <queue>

using namespace std;

int const SIZE = 1002;

typedef struct point{
	int x, y, step;
}point;

int map[SIZE][SIZE] = {0};
int n;
int tarx, tary;

//�������� 
int sp[5] = {0, 1, 0, -1, 0};

queue<point> q;

int Bfs(int r, int c)
{
	map[r][c] = 1;
	point p;
	p.x = r;
	p.y = c;
	p.step = 0;
	q.push(p);
	
	while( !q.empty() )
	{
		point temp = q.front();
		q.pop();
		
		//����Ŀ�� 
		if( temp.x == tarx && temp.y == tary )
			return temp.step;
		
		for( int i = 0; i <= 3; i++ )
		{
			int x = temp.x + sp[i];
			int y = temp.y + sp[i + 1];
		
			//�ж�Խ�����ͨ 
			if( x < 1 || y < 1 || x > n || y > n || map[x][y] )
				continue;
							
			p.x = x;
			p.y = y;
			p.step = temp.step + 1;
			q.push(p);
			map[x][y] = 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n;
	
	char t[SIZE];
	for( int i = 1; i <= n ; i++ )
	{
		cin >> t;
		for( int j = 1; j <= n; j++ )
			map[i][j] = t[j - 1] - 48 ;
	}
	
	int x, y;
	cin >> x >> y;
	cin >> tarx >> tary;
	
	cout << Bfs(x, y);
	
	return 0;
}

