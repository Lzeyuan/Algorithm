#include <iostream>

using namespace std;

typedef struct{
	char str[110];
	int number;
	int length;
}president;

int pan(president &p, president &q)		//判断谁大 p 大就返回 1 ，q大返回 -1 
{
	if(p.length > q.length)				//位数比较
	{
		return 1;
	}
	else if(p.length < q.length)
	{
		return -1;
	}
	
	int i;
	for(i = 0; i < p.length; i++)		//每位对比 
	{
		if(p.str[i] > q.str[i])
		{
			return 1;
		}
		else if(p.str[i] < q.str[i])
		{
			return -1;
		}
	}
	
	return 0;					//相同则返回 0 
}

void Bubble(president *p, int n)
{
	int i, j, flag = 1;
	for(i = 1; i <= n && flag; i++) 
	{
		flag = 0;
		for(j = 1; j <= n - i; j++)
		{
			if(pan(p[j],p[j+1]) == 1)
			{
				flag = 1;
				president temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

int main()
{
	president pres[21];
	int n;
	int i;
	
	cin >> n;		//有n个人 候选人 
	
	for(i = 1; i<= n; i++) 
	{
		pres[i].number = i;		//第i个候选人 
		cin >> pres[i].str; 	//有x张票 
		
		int j = 0;				//票的位数 
		while(pres[i].str[j])
		{
			j++;
		}
		pres[i].length = j;
	}
	
	Bubble(pres, n);		//排序 
	
	cout << pres[n].number << "\n" << pres[n].str;
	
    return 0;
}



