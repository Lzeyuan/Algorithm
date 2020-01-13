#include <iostream>

using namespace std;

//const int MAX = 5000;

typedef struct {
	int exam;
	int number;
}Player;

void Bubble(Player *player, int length)
{
	int i, j;
	
	for(i = 1; i <= length; i++)
	{
		for(j = 1; j <= length - i; j++)
		{
			if(player[j].exam > player[j+1].exam)
			{
				Player temp;
				temp = player[j];
				player[j] = player[j+1];
				player[j+1] = temp; 
			}
			
			if(player[j].exam == player[j+1].exam && player[j].number < player[j+1].number)
			{
				Player temp;
				temp = player[j];
				player[j] = player[j+1];
				player[j+1] = temp; 
			}
		}
	}
} 

int main()
{
	int m, n, interviewer, line;
	int i, t;
	Player player[5000 + 1],*p;

	p = player;		//指针指向记录数组 

	cin >> n >> m;			//读入n个人参赛，录取m个人 

	interviewer = int(m * 1.5);		//成绩 >= 第m*1.5个人的成绩，进入面试，同排名也进入 

	for (i = 1; i <= n; i++)		//读入数据 
	{
		cin >> player[i].number >> player[i].exam;
	}
	

	Bubble(p,n); 


	line = player[n - interviewer + 1].exam;		//录取线 

	i = n;		//共n个人 
	t = 0; 
	while (player[i].exam >= line)		//筛选 t 个人 
	{
		t++;
		i--;
	}

	cout << line << ' ' << t << endl;
	t = n - t + 1;
	for(i = n; i >= t; i--)
	{
		cout << player[i].number << " " << player[i].exam << endl;
	}

	return 0;
}
