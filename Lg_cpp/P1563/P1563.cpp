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
	
	//��ʼ�� 
	memset(q,0,sizeof(q));
	cin >> n >> m;
	
	cin >> drection >> name; 
	strcpy(q[0],name);
	drectionQ[0] = drection;
	
	//����λ�� 
	for(i = n-1; i > 0; i--)
	{
		cin >> drection >> name; 
		strcpy(q[i],name);
		drectionQ[i] = drection;
	}
	
	//�ж�λ��
	for (i = 0; i < m; i++)
	{
		cin >> drectionCom >> stepCom;
		
		if(!drectionQ[p])		//���� 
		{
			if (!drectionCom)	//���� 
			{
				p = (p+stepCom)%n; 	//˳ʱ�� 
			}
			else{				//���� 
				p = (p-stepCom)%n;	//��ʱ�� 
			}
		}
		else{					//���� 
			if (!drectionCom)
			{
				p = (p-stepCom)%n; 	//��ʱ�� 
			}
			else{
				p = (p+stepCom)%n;	//˳ʱ�� 
			}
		} 	      	
		if (p < 0)			//���� 
			p += n;			//!!!!!!
		cout <<  q[p] << endl;
	}
	
	cout <<  q[p] << endl;
	
    return 0;
}

