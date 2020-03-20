#include <iostream>

using namespace std;
const int MAXSIZE = 6+1;

bool a[MAXSIZE][MAXSIZE] = {0},  book[MAXSIZE][MAXSIZE] = {0};

int total = 0;
int n, m;
int T;
int tarx, tary;

int next1[4][2] = { {1, 0},		//������ 
				   {0, 1}, 		//������ 
					{-1, 0},	//������ 
					{0, -1}};	//������ 

void dfs(int startx, int starty)
{
	/*
	* ע�⣡������һ��Ҫ������һ��ջ���жϣ��������ڳ��������������ж�
	* ��Ϊ�п�������ǰ�߿��Ե�Ŀ�ĵأ���������Ҳ���ԣ�ֻ��·�̲�ͬ���� 
	*/ 
	
	//�ж��Ƿ񵽴�Ŀ�ĵ� 
	if( startx == tarx && tary == starty )
	{
		total++;
		return;
	} 
	
	for(int i = 0; i <= 3 ; i++)
	{
		int tx = startx + next1[i][0];
		int ty = starty + next1[i][1];
		
		//�ж��Ƿ��Ѿ��߹�||���ϰ���
		if( a[tx][ty] || book[tx][ty] ) 
			continue;
			
		//�ж��Ƿ�Խ��
		if(tx > m || ty > n || tx < 1 || ty < 1)
			continue;
		

		book[tx][ty] = true;
		dfs(tx, ty);		//�����濪ͷ��ע�ͣ� 
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

