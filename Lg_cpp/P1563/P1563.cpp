#include  <iostream>
#include <cstring>

#define MAXSIZE 100001

using namespace std;

int main()
{
	char q[MAXSIZE][11];
	char name[11];
	int drectionQ[MAXSIZE]={0};
	int n, m;
	int i, j, drection;
	int drectionCom, stepCom;  
	int p = 0;
	
	//初始化 
	memset(q,0,sizeof(q));
	cin >> n >> m;
	
	cin >> drection >> name; 
	strcpy(q[0],name);
	drectionQ[0] = drection;
	
	//读入位置 
	for(i = n-1; i > 0; i--)
	{
		cin >> drection >> name; 
		strcpy(q[i],name);
		drectionQ[i] = drection;
	}
	
	//判断位置
	for (i = 0; i < m; i++)
	{
		cin >> drectionCom >> stepCom;
		
		if(!drectionQ[p])		//朝内 
		{
			if (!drectionCom)	//向左 
			{
				p = (p+stepCom)%n; 	//顺时针 
			}
			else{				//向右 
				p = (p-stepCom)%n;	//逆时针 
			}
		}
		else{					//朝外 
			if (!drectionCom)
			{
				p = (p-stepCom)%n; 	//逆时针 
			}
			else{
				p = (p+stepCom)%n;	//顺时针 
			}
		} 	      	
		if (p < 0)			//负数 
			p += n;			//!!!!!!
		cout <<  q[p] << endl;
	}
	
	cout <<  q[p] << endl;
	
    return 0;
}

