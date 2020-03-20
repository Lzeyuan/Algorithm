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

	p = player;		//ָ��ָ���¼���� 

	cin >> n >> m;			//����n���˲�����¼ȡm���� 

	interviewer = int(m * 1.5);		//�ɼ� >= ��m*1.5���˵ĳɼ����������ԣ�ͬ����Ҳ���� 

	for (i = 1; i <= n; i++)		//�������� 
	{
		cin >> player[i].number >> player[i].exam;
	}
	

	Bubble(p,n); 


	line = player[n - interviewer + 1].exam;		//¼ȡ�� 

	i = n;		//��n���� 
	t = 0; 
	while (player[i].exam >= line)		//ɸѡ t ���� 
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
