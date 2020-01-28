#include<bits/stdc++.h>
using namespace std;
int n,v,f[15000],i,j,w,m;
int main()
{
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&w,&m);//每读一个物品就处理一个 
        for(j=v;j>=w;j--)//模拟背包剩余容量 
            if(w<=j) f[j]=max(f[j],f[j-w]+m);  //选择那与不拿（取最大值） 
        for(j=1;j<=v;j++)
    		cout << f[j] << ' ';
    	cout << endl;
    }
    
    for(j=1;j<=v;j++)
    	cout << f[j] << ' ';
    
    printf("%d",f[v]);//最后一个即为最大值 
    
    return 0;    
}
