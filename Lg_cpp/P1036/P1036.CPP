#include <iostream>
#include <cmath>

using namespace std;

int a[21] = {0};

bool isprime(int x)
{
	for(int i = 2; i <= (int)sqrt(x); i++)
		if(x%i == 0)
			return false;
	return true;
}

int ans = 0;

int dfs(int start, int n, int k, int already_sum)
{
	if(k == 0)
		return isprime(already_sum);
	int t = 0;
	for(int j = start; j <= n; j++)
	{
		t += dfs(j+1, n, k-1, already_sum + a[j]);
	}
	return t;
}

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	for(int i = 1; i <=n ; i++)
		cin >> a[i];
	
	cout << dfs(1,n,k,0);
	
	return 0;
}
