#include<bits/stdc++.h>
using namespace std;
int n,v,f[15000],i,j,w,m;
int main()
{
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&w,&m);//ÿ��һ����Ʒ�ʹ���һ�� 
        for(j=v;j>=w;j--)//ģ�ⱳ��ʣ������ 
            if(w<=j) f[j]=max(f[j],f[j-w]+m);  //ѡ�����벻�ã�ȡ���ֵ�� 
        for(j=1;j<=v;j++)
    		cout << f[j] << ' ';
    	cout << endl;
    }
    
    for(j=1;j<=v;j++)
    	cout << f[j] << ' ';
    
    printf("%d",f[v]);//���һ����Ϊ���ֵ 
    
    return 0;    
}
