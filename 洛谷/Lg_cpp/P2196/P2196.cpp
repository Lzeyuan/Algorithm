#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
bool f[21][21];//��¼�Ƿ���·������
int a[21];//��¼������
int path[21],ans[21],cnt;//path��¼·����ans��¼�𰸣�cnt��¼���˶��ٸ���
bool b[21];//��¼�õ��Ƿ��߹�
int n;
int maxx;//��¼�ڵ���������
bool chck(int x)//����Ƿ��ܼ���������
{
    for(int i=1;i<=n;i++)
    {
        if(f[x][i]&&!b[i]) return false;
    }
    return true;
}
void dfs(int x,int stp,int sum)//x��¼����λ�ã�stp��¼���˼����㣬sum��¼�ڵĵ�����
{
    if(chck(x))
    {
        if(maxx<sum)//�������ֵ��·��
        {
            maxx=sum;
            cnt=stp;
            for(int i=1;i<=stp;i++)
            ans[i]=path[i]; 
        }
        return ;
    }
    for(int i=1;i<=n;i++)//Ѱ����һ����ȥ�ĵط�
    {
        if(f[x][i]&&!b[i])
        {
            b[i]=1;//����߹�
            path[stp+1]=i;//��¼·��
            dfs(i,stp+1,sum+a[i]);
            b[i]=0;//����
        }

    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        cin>>f[i][j];//�����ǵ���ߣ���Ŀûɶ����������ҵ��˰��Сʱ��
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=1;
        path[1]=i;//��¼���
        dfs(i,1,a[i]);
        b[i]=0;
    }
    for(int i=1;i<=cnt;i++)
    cout<<ans[i]<<' ';
    cout<<endl<<maxx;
    return 0;
}
