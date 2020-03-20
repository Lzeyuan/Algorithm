#include <iostream>

using namespace std;

typedef struct{
	char str[110];
	int number;
	int length;
}president;

int pan(president &p, president &q)		//�ж�˭�� p ��ͷ��� 1 ��q�󷵻� -1 
{
	if(p.length > q.length)				//λ���Ƚ�
	{
		return 1;
	}
	else if(p.length < q.length)
	{
		return -1;
	}
	
	int i;
	for(i = 0; i < p.length; i++)		//ÿλ�Ա� 
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
	
	return 0;					//��ͬ�򷵻� 0 
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
	
	cin >> n;		//��n���� ��ѡ�� 
	
	for(i = 1; i<= n; i++) 
	{
		pres[i].number = i;		//��i����ѡ�� 
		cin >> pres[i].str; 	//��x��Ʊ 
		
		int j = 0;				//Ʊ��λ�� 
		while(pres[i].str[j])
		{
			j++;
		}
		pres[i].length = j;
	}
	
	Bubble(pres, n);		//���� 
	
	cout << pres[n].number << "\n" << pres[n].str;
	
    return 0;
}



