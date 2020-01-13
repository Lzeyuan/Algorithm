#include <iostream>
#include <cstdio>

using namespace std;

void Dfs( int row, int col );

bool map[201][201] = {false};		//��ͼ 
bool book[201][201] = {false};	//��¼�Ƿ������
int r, c;		//���� 

int main()
{
	//�����С���
	cin >> r >> c;
	
	//�����ͼ 
	for( int i = 1; i <= r; i++ )
		for( int j = 1; j <= c; j++ ) 
		{
			int loca;
			scanf("%1d", &loca);
			
			//����0��¼ 
			if( loca > 0 )
				map[i][j] = true;
			else
				map[i][j] = false;
		}
	
	//��ʼ����Ѱ��ϸ����
int count = 0;	//��¼ϸ���� 
	for( int i = 1; i <= r; i++ )
		for( int j = 1; j <= c; j++ ) 
		{
			//����ϸ����û������ 
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

//�������� 
int step[5] = { 0, 1, 0, -1, 0}; 
void Dfs( int row, int col )
{
	for( int i = 0; i <= 3; i++ )
	{
		int x = row + step[i];
		int y = col + step[i+1];
		
		//�ж��Ƿ�Խ��
		if( x < 1 || y < 1 || x > r || y > c )
			continue;
		
		//�ж��Ƿ���������Ƿ������ϸ����һ���� 
		if( map[x][y] && !book[x][y] )
		{
			book[x][y] = true;
			Dfs( x, y );
		}
	} 
}


