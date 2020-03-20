#include <iostream>
#include <cmath>

using namespace std;

const int N = 501;
const int MAXSIZE = 21;

typedef struct{
	int x;
	int y;
	int conut;
}Date;

typedef struct {
	Date date[N];
	int length;
}Point;

void Qsort(Point &P,int left, int right)
{
	int i = left, j = right, t;
	
	if(i >= j)
	{
		return;
	}
	
	
	t = P.date[left].conut;
	
	while(i < j)
	{
		while(i < j && t <= P.date[j].conut)
			j--;
		while(i < j && t >= P.date[i].conut)
			i++;
			
		if(i < j)
		{
			Date temp = P.date[i];
			P.date[i] = P.date[j];
			P.date[j] = temp;
		}
	}
	
	Date temp = P.date[left];
	P.date[left]  = P.date[i];
	P.date[i] = temp;
	
	Qsort(P, left, i-1);
	Qsort(P, i+1, right);
	
}

int main()
{
	Point *p;
	p = new Point;
	int map[MAXSIZE][MAXSIZE] = {0};
	int m, n, time;
	int i, j, sum = 0;
	
	p->length = 0;
	
	cin >> m >> n >> time;
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] > 0)
			{
				int t = ++p->length;
				p->date[t].x = i, p->date[t].y = j;
				p->date[t].conut = map[i][j];
			}
		}
	}

	Qsort(*p, 1, p->length);
	
	int temp;
	int tx = -1, ty = -1;
	
	for(i = p->length; i >= 1; i--)
	{
		temp = time;
		
		temp -= abs(tx - p->date[i].x) + (p->date[i].x + 1);
		if(ty != -1) 
			temp -= abs(ty - p->date[i].y);

		temp--; 
		
		if(temp >= 0)
		{
			tx = p->date[i].x;
			ty = p->date[i].y;
			time = temp;
			
			if(temp != 0)
				time += p->date[i].x + 1;
			sum += p->date[i].conut; 			
		}
		else
		{
			break;
		}
	}
	
	cout << sum;

    return 0;
}



