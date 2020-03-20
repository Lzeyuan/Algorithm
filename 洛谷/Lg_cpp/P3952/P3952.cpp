#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>

using namespace std;

typedef struct
{
	char name;
	int w;
}sen;

int npow(char *c)
{
	int i = 0;
	int sum = 0;
	
	while(c[i])
	{
		if(isdigit(c[i]))
		{
			sum += sum*10 + c[i] - 48; 
		}
		i++;
	}
	cout << "M = " << sum << endl;
	return sum;
}

int main()
{
	sen senten[101];
	sen temp;
	stack <sen>senbook;
	int l, n, w, answerbook[101] = {0};
	int i, j, k;
	char str[20];
	int d[2][100];
	int book[130] = {0};
	char answer1[20]; 
	int answer2, power, max;		//�жϵ�ǰǶ�׵ȼ� 
	
	
	cin >> l;		//׼���ж�L������ 
	
	for(i = 1; i <= l; i++)		
	{
		cin >> n >> answer1;		//׼���ж�n�д��룬����ش� 
		
		while(!senbook.empty())		//���ջ 
		{
			senbook.pop();
		}
		answer2 = 0;				//��ʼ��ʱ�临�Ӷ�Ϊ1 
		memset(book, 0, sizeof(book));		//�ظ�������¼��0 
		
		power = max = 0;		//Ƕ�׵ȼ� 
		
		for(j = 1; j <= n; j++)
		{
			cin.sync();
			cin.getline(str,101);				//������� 

			
			if(str[0] == 'E')		// ��ΪE���ջ 
			{
				power--;
				temp = senbook.top();
				senbook.pop();
				book[temp.name] = 0;
				if(temp.w)
				{
					answer2 += 1;
				}
				
			}
			else					//�����ж� 1.�����Ƿ��ظ� 2.ʱ�临�Ӷ� 
			{
				power++;
				if(book[str[2]] == 1)		//�����ظ� ERR! 
				{
					cout << str[2] << endl;
					answer2 = -1;
					break;
				}
				else
				{
					book[str[2]] = 1;
				}
				
				if(str[4] == 'n')				//���X = n ��ѭ�� 
				{
					senten[j].name = str[2];
					senten[j].w = 0;
				} 
				else						//���� m += 1 
				{
					if(power > max)
					{
						senten[j].name = str[2];
						senten[j].w = 1;
					}
				} 
				
				senbook.push(senten[j]);
				max = max > power? max : power;
			}
		}
		
		//cout << "answer2 = " << answer2 << endl;
		
		if(answer2 == -1)
		{
			answerbook[i] = -1;
			continue;
		}
		
		if(senbook.empty())
		{
			if(answer2 == npow(answer1))
			{
				answerbook[i] = 1;
			}
			else
			{
				answerbook[i] = 0;
			}
		}
		else
		{
			answerbook[i] = -1;
		}
	}
	
	for(i = 1; i <= l; i++)
	{
		if(answerbook[i] == 1)
		{
			cout << "Yes" << endl;
		}
		else if(answerbook[i] == 0)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "ERR" << endl;
		}
		
	}
	
    return 0;
}



