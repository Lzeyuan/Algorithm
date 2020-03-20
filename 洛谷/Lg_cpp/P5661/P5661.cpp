#include <iostream>

using namespace std;

typedef struct{
	int cost;
	int time;
}ticket;

const int N = 1001;

int main()
{
	ticket qSub[N];
	int n, i;
	int spend = 0;
	int head = 1, tail = 1;
	
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		int way, cost, time;
		cin >> way >> cost >> time;
		cout << "Subcost = " << qSub[head].cost << ",cost = " << cost << endl;
		if(!way)				//����
		{
			qSub[tail].cost = cost;
			qSub[tail].time = time;
			tail++;
		}
		else
		{
			
			if(qSub[head].cost >= cost && head <= tail)		//������Ǯ�ȹ����� 
			{
				if(time - qSub[head].time <= 45)		//û�г�ʱ 
				{
					spend += qSub[head].cost;
					head++;
					cout << "spend = " << spend << endl;
					continue;
				}
			}
			spend += cost + qSub[head].cost;
			head++;
		}
		cout << "spend = " << spend << endl;
	}
	
	cout << spend;
	
	
    return 0;
}



