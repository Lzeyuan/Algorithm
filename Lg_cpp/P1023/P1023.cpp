#include  <iostream>

#define MAXSIZE 100001

using namespace std;

int main()
{
	int expect, price[MAXSIZE] = {0}, quantity[MAXSIZE] = {0}, cost = 0;
	int profit[MAXSIZE] = {0};
	int i = 1, max = -99999999 , f = 0, result = 0;
	
	cin >> expect;
	
	while(1)
	{
		int a, b;
		cin >> a >> b;
		
		if(a == -1 && b == -1) 	//�˳�ѭ�� 
			break;
		
		int cha = 0, t = a;
		
		if( i > 2 && price[i-1] - price[i-2] > 1)
		{
			i--;
			cha = price[i] - price[i-1];
			t = price[i];
			for(int j = price[i-1]+1; j <= t; j++)
			{
				price[i] = j;
				quantity[i] = quantity[i-1] - cha;
				i++;
			}
		} 
		
		i++;		//��һ���� 
	}

	int d;
	cin >> d; 

	while(quantity[i-1] - d > 0)	//����ʣ�µ����� 
	{
		quantity[i] = quantity[i-1] - d;
		price[i] = price[i-1] + 1;
		profit[i] = (price[i] - cost)*quantity[i];
		
		if(max < profit[i])		//��¼�������͵�ʱ�ۼ� 
		{
			max = profit[i];
			f = price[i];
		}
		i++;		//��һ���� 
	}
	
	i--;
	cout << quantity[i];
	int count = i, tax = -1, subsidy = 1;
	
	while(f != expect) 
	{
		max = -9999999;
		for(int j = 1; j <= count; j++)
		{
			profit[j] = (price[j] - cost + tax)*quantity[j];
			if(max < profit[j])		//��¼�������͵�ʱ�ۼ� 
			{
				max = profit[j];
				f = price[j];
			}
		}
		
		tax--;
		
		if(f == expect)
		{
			result = ++tax;
			break;	
		}
			
		max = -9999999;
		for(int j = 1; j <= count; j++)
		{
			profit[j] = (price[j] - cost + subsidy)*quantity[j];
			if(max < profit[j])		//��¼�������͵�ʱ�ۼ� 
			{
				max = profit[j];
				f = price[j];
			}
		}
		
		subsidy++;
		
		if(f == expect)
		{
			result = --subsidy;
			break;	
		}
		
	}
	 
	cout << result;
	 
    return 0;
}

