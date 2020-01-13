#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 1501;

char road[MAXSIZE][MAXSIZE] = {0};
bool book[MAXSIZE][MAXSIZE] = {false};
int st_x, st_y;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};		//左下右上 

bool walked(int x, int y)		//判断是否通路 
{
	if(!book[x][y] && road[x][y] != '#')
		return true;
	return false;
}

void dfs()
{
	
}

int main()
{
	int n, m;
	
	while(cin >> n >> m)
	{
		
		memset(road, 0, sizeof(road));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> road[i][j];
				if(road[i][j] == 'S')
					st_y = i, st_x = j;
				book[i][j] = true; 
			}
		}
		
		/*cout << "=======================\n";
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cout << road[i][j];
			}
			cout << endl;
		}
		cout << "=======================\n";
		*/
		
		
		
	}
    return 0;
}

/*
	#.#.#/#.#.#
	..#../..#..
	#####/#####
	..#../..#..
	#.#.#/#S#.#
	===========
	#.#.##.#.#
	..#....#..
	##########
	..#....#..
	#.#.##.#.#
*/

