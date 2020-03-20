#include <iostream>

using namespace std;

//const int MAX = 5000;

typedef struct {
	int exam;
	int number;
}Player;

void quickSort(Player *player, int left, int right)
{
	Player temp;
	int i, j;
	
	if (left >= right)
		return;

	i = left, j = right;

	while (i < j)
	{		
		while (i < j && player[left].number <= player[i].number)
			i++;
		while (i < j && player[left].number >= player[j].number)
			j--;


		if (i < j)
		{
			temp = player[i];
			player[i] = player[j];
			player[j] = temp;
		}
	}

	temp = player[left];
	player[left] = player[i];
	player[i] = temp;

	quickSort(player, left, i-1);
	quickSort(player, i + 1, right);

	return;
}

void Bubble(Player *player, int length)
{
	int i, flag = 1, j;
	
	for(i = 1; i <= length && flag; i++)
	{
		flag = 0;
		for(j = 1; j <= length - i; j++)
		{
			if(player[j].exam > player[j+1].exam)
			{
				Player temp;
				temp = player[j];
				player[j] = player[j+1];
				player[j+1] = temp; 
				flag = 1;
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
	
	//quickSort(p,1,n);			//数据排序 
	quickSort(p,1,n);
	/*cout << "======================" << endl;
	for(i = 1; i<= n; i++)
	{
		cout << player[i].number <<  ' '<< player[i].exam << endl;
	}
	cout << "======================" << endl;
	*/
	Bubble(p,n); 
	
	/*cout << "======================" << endl;
	for(i = 1; i<= n; i++)
	{
		cout << player[i].number <<  ' '<< player[i].exam << endl;
	}
	cout << "======================" << endl;
	 */

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
