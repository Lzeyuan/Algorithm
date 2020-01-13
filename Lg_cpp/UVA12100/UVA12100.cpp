#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Task{
	int number;
	int w;
};

inline int read()
{
	int s = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch >'9')
	{
		if(ch == '-')
		{
			f = -1;
			ch = getchar();
		}
	}
	
	while(ch >= '0' && ch <='9')
	{
		s = s*10 + ch - '0';
		ch = getchar();
	}
	return s*f;
}
		
int main()
{
	int t;
	t = read();
	Task task[105*100];
	while(t--)
	{
		int order[105];
		memset(order,0,sizeof(order));
		
		int l = 1, ans = 0, k = 0;
		int n = 0, m = 0;
		
		n = read();
		m = read();
		m++;
		int r = n;
		
		for(int i = 1; i <= n; i++)
		{
			task[i].w = read();
			task[i].number = i;
			order[++k] = task[i].w;
		}
		
		sort(order+1, order+k+1);
		
		while(l <= r)
		{
			Task u = task[l++];
			
			if(u.w != order[k])
				task[++r] = u;
			else
			{
				ans++;
				k--;
				if(u.number == m)
				break;
			}
		}
		cout << ans << endl;
	}

    return 0;
}



