#include <iostream>

#define MAXSIZE 10001

using namespace std;

int main()
{
	int n, sum = 0, time = 0;
	int a[MAXSIZE] = {0}, p = 1;
	int problem = 0, slution = 0;
	
	cin >> n;		//��ʼ������N 
	
	for(int i = 1; i <= n; i++)		//����ÿ�ѵ����� 
	{
		cin >> a[i];
		sum += a[i]; 
	}
	
	int power = sum/n;		//��һ�ѵı����� 
	
	for(int i = 1; i <= n; i++)	 
	{
		if(a[i] == power)		//�պñ��� 
			continue;
			
		if(a[i] < power)		//�ж��Ƿ񱥺� 
		{
			problem += a[i];		//���¼ȱ���� 
		}
		else if(a[i] > power)
		{
			slution += a[i] - power;		//�� ��¼����� 
		}
		
		if(slution >= problem)		//���������ڵ���ȱ����ʼ�ƶ� 
		{
			if(i != n)
			{
				int t = a[i] - (slution - problem) - power;
				a[i] = power;		//���ǰ�������ʣ����� 
				a[i-1] += t;
				time++;
				if(t > 0)
				{
					a[i+1] += t;
					time++;
				}
			}
			
			for(int j = i; j >= p; j--)
			{
				if(a[j] > power)
				{
					if(a[i+1] < power)
					{
						
					}
				}
			} 
		}
		
	}
	
    return 0;
}



