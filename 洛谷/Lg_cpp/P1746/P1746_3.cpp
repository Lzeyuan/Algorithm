#include <iostream>
#include <queue>

using namespace std;

int const SIZE = 1002;

typedef struct point{
	int x, y;
	int s;
	int f;
}point;

int map[SIZE][SIZE] = {0};
int n;
int tarx, tary;

//上右左下 
int sp[5] = {0, 1, 0, -1, 0};

int main()
{
	cin >> n;
	
	char t[SIZE];
	for( int i = 0; i < n ; i++ )
	{
		cin >> t;
		for( int j = 0; j < n; j++ )
			map[i][j] = t[j] - 48;
	}
	
	int x, y;
	cin >> x >> y;
	cin >> tarx >> tary;
	
	//队列初始化
	int tail = 1, head = 1;
	
	//起点 
	point que[tail];
	que[tail].x = x;
	que[tail].y = y;
	que[tail].f = 0;
	que[tail].s = 0; 
	tail++;
	map[x][y] = 1;
	
	int flag = 0;
	
	while( head < tail )
	{
		for( int k = 0; k <= 3; k++ )
		{
			int tx = que[head].x + sp[k];
			int ty = que[head].y + sp[k + 1];
			
			if( x < 0 || x > n || y < 0 || y >n  )
				continue;
			
			
		}
	}
	
	return 0;
}

