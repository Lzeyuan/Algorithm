#include <iostream>

using namespace std;

int const MAXSIZE = 20001;
int n, m, k;

bool map[MAXSIZE][MAXSIZE] = {false};		//地图 

//堵路 
void Jam(int r, int c)
{
	int i, j, flag = 1;
	
	//行 
	for( i = 1; i <= m; i++ )
	{
		if(!map[r][i])
			map[r][i] = true;
	}
	
	//列	 
	for( i = 1; i <= n; i++ )
	{
		if(!map[i][c])
			map[i][c] = true;
	}
	
	//斜右 
	for( i = 1; i <= n && flag; i++ )
		for( j = 1; j <= m && flag; j++  )
		{
			if( (r - c) == (i - j) )
				flag = 0;
		}
	
	i--, j--;
	//开始堵路 
	while(1 && !flag)
	{
		if(!map[i][j])
			map[i][j] = true;
		i++, j++;
		if( i > n || j > m )
			break;
	}
	
	flag = 1;
	//斜左
	for( i = 1; i <= n && flag; i++ )
		for( j = 1; j <= m && flag; j++  )
		{
			if( (r + c) == (i + j) )
				flag = 0;
		}
		
	i--, j--;
	//又开始堵路 
	while(1 && !flag)
	{
		if(!map[i][j])
			map[i][j] = true;
		i++, j--;
		if( i > n || j < 1 )
			break;
	}
}

int main()
{
	cin >> n >> m >> k;
	
	int r, c;
	for( int i = 1 ; i <= k; i++)
	{
		cin >> r >> c; 
		Jam( r, c );
	}
	
	Jam( r, c );
	
	int ans = 0;
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++  )
		{
			if( !map[i][j] )
				ans++; 
		}
		
	cout << ans;
	
	return 0;
}
