//dfs会时间爆炸 （ n > 20 用dp) 该题 n <= 20  
#include <iostream>

using namespace std;

const int MAXSIZE = 21;

int n; 
int book[MAXSIZE][MAXSIZE] = {0};
int w[MAXSIZE] = {0};
int ans[MAXSIZE] = {0};
int alwalk[MAXSIZE] = {0};
int maxx = 0;
int count = 0;
int b [MAXSIZE] = {0};

bool check(int depth)
{
	for(int i = 1; i <= n; i++)
		if(book[depth][i] && !b[i])
			return true;
	return false;
}

void dfs(int depth,int step,int already_sum)
{
	if(already_sum > maxx && !check(depth))
	{
		int j;
		maxx = already_sum;
		for(j = 1; j < step; j++)
			ans[j] = alwalk[j];
		ans[j] = depth;
		count = step;
	}
	
	for(int i = 1; i <= n-depth ; i++)
	{
		if(book[depth][i])
		{
			alwalk[step] = depth;
			b[i] = 1;
			dfs(i+depth, step+1, already_sum + w[i+depth]);
			b[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	
	for(int i = 1; i <= n ; i++)
		cin >> w[i];
	
	for(int i = 1; i < n ; i++)
	{
		for(int j = 1; j <= n - i; j++)
		{
			cin >> book[i][j];
		}
	} 
	
	for(int i = 1; i <= n; i++)
		dfs(i,1,w[i]);
	
	for(int i = 1; i < count; i++)
		cout << ans[i] << " ";
		cout << ans[count] << endl;
	cout << maxx;	
		
    return 0;
}



