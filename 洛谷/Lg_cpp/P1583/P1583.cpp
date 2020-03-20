#include <iostream>
#include <algorithm> 
 
using namespace std;

const int MAXSIZE = 20000;

typedef struct{
	int number;
	int w;
}Friend;

void Bubble(Friend *f, int length)		//冒泡排序 
{
	int flag = 1;
	for(int i = 1; i <= length && flag; i++)
	{
		flag = 0;
		for(int j = length; j >= 1+i; j--)
		{
			if(f[j].w > f[j-1].w)
			{
				flag = 1;
				Friend temp;
				temp = f[j];
				f[j] = f[j-1];
				f[j-1] = temp;
			}
			if(f[j].w == f[j-1].w && f[j].number < f[j-1].number )
			{
				flag = 1;
				Friend temp;
				temp = f[j];
				f[j] = f[j+1];
				f[j+1] = temp;
			}
		}
	}
}

bool cmp(Friend f1, Friend f2)
{
	if(f1.w != f2.w)
		return f1.w > f2.w;
	return f1.number < f2.number; 
} 

int main()
{
	Friend f[MAXSIZE + 1];
	int n, k;
	
	cin >> n >> k;		//编号w[i] 

	int c[10 + 1]= {0};		//输入额外权值 
	
	for(int i = 1; i <= 10; i++)		
	{
		cin >> c[i];
	}
	
	for(int i = 1; i <= n; i++)		//输入初始权值 
	{
		f[i].number = i;
		cin >> f[i].w;
	}
	
	//Bubble(f,n);		//排序D[i] 
	sort(f+1,f+n+1,cmp) ;
	
	for(int i = 1; i <= n; i++)		//增值 
	{
		f[i].w += c[(i-1)%10+1];
	}
	
	//Bubble(f,n);		//在排序w[i] 
	sort(f+1,f+n+1,cmp) ;

	for(int i = 1; i <= k; i++)
	{
		cout << f[i].number << " ";
	}
	
    return 0;
}


