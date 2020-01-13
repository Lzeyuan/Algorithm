#include <iostream>

#define MAXSIZE 10001

using namespace std;

int main()
{
	int n, sum = 0, time = 0;
	int a[MAXSIZE] = {0}, p = 1;
	int problem = 0, slution = 0;
	
	cin >> n;		//初始化读入N 
	
	for(int i = 1; i <= n; i++)		//读入每堆的数据 
	{
		cin >> a[i];
		sum += a[i]; 
	}
	
	int power = sum/n;		//求一堆的饱和数 
	
	for(int i = 1; i <= n; i++)	 
	{
		if(a[i] == power)		//刚好饱和 
			continue;
			
		if(a[i] < power)		//判断是否饱和 
		{
			problem += a[i];		//否记录缺少数 
		}
		else if(a[i] > power)
		{
			slution += a[i] - power;		//是 记录溢出数 
		}
		
		if(slution >= problem)		//如果溢出大于等于缺少则开始移动 
		{
			if(i != n)
			{
				int t = a[i] - (slution - problem) - power;
				a[i] = power;		//解决前面问题后剩余多少 
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



