#include <iostream>
#include <cmath>

using namespace std;

const int MAXSIZE = 20;

int n, k;
int a[MAXSIZE] = {0};

bool isprime(int x)
{
	for(int i = 2; i <= (int)sqrt(x); i++)
		if(x%i == 0)
			return false;
	return true;
}

int dfs(int time, int j, int already_sum)
{
	if(time == 0)
	{
		if(isprime(already_sum))
			return 1;
		return 0;
	}
	
	int sum = 0;
	for(int i = j; i <= n; i++)
		sum += dfs(time-1, i+1, already_sum + a[i]);
	return sum;
}

int main()
{
	cin >> n >> k;
	
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	cout << dfs(k, 1, 0);
	
    return 0;
}



