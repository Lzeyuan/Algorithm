//这道题用二维会爆
#include<bits/stdc++.h>
using namespace std;
int n,v,f[15000],i,j,w[15000],m[15000];
int main()
{
    scanf("%d%d", &n, &v);
    for( i = 1; i <= n; i++ )
        scanf("%d%d", &w[i], &m[i]);//每读一个物品就处理一个  
    
    int tot = 0;
	for( i = 1; i<= n; i++ )    
		tot += m[i];

	for( i = 1; i <= n; i++)
		for( j = v; j >= max( v - tot, w[i] ) ; j--)
			f[j] = max( f[j], f[j - w[i]] + m[i] );
    
    printf("%d",f[v]);//最后一个即为最大值 
    return 0;    
}
