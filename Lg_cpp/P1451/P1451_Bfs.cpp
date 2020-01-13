#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct{
	int x, y;
}point; 

void Bfs( point );

point p;
bool map[201][201] = {false};		//��ͼ 
bool book[201][201] = {false};	//��¼�Ƿ������
int r, c;		//���� 
int count = 0;
queue<point> qq;

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
	
	for( int i = 1; i <= r; i++ )
	{	
		for( int j = 1; j <= c; j++)
		{
			//����ϸ����û������ 
			if( map[i][j] && !book[i][j] )
			{
				p.x = i;
				p.y = j;
				book[i][j] = true;		//��¼������ 
				count++;		//ϸ����+1 
				Bfs( p );		//����������� 
			}
		}
	}
	
	cout << count;
    return 0;
}

//�������� 
int step[5] = { 0, 1, 0, -1, 0}; 

//����������� 
void Bfs( point p )
{
	qq.push(p);
	
	while( !qq.empty() )
	{
		point temp = qq.front();		//��¼��ͷ���� 
		qq.pop();			//���� 
		
		//��ʼ���� 
		for( int k = 0; k <= 3; k++ )
		{
			int x = temp.x + step[k];
			int y = temp.y + step[k+1];
			
			//�ж��Ƿ�Խ��
			if( x < 1 || y < 1 || x > r || y > c )
				continue;
				
			//����ϸ�� 
			if( map[x][y] && !book[x][y] )
			{
				point t;
				t.x = x;
				t.y = y;
				qq.push(t);		//��� 
				book[x][y] = true;		//��� 
			}
		}
	}
}


