/*
	F y 10 n	���������������ֵ�� 
*/

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

typedef struct{
	char x;
	int o;
}Program;  

const int MAXSIZE = 100;

int read_se(Program &p, char *c1, char *c2)		//�ж� 
{

	if(c2[0] == 'n')
	{
		p.o = 1;
		return 1;
	}
	p.o = 0;
	return 0;
}

int main()
{
	int t;
	
	cin >> t;		//��n������
	
	for( int i = 1; i <= t; i++ )		//ѭ���ж�n�� 
	{
		int book[128] = {0};		//��¼���� 
		Program pra[MAXSIZE + 1];
		int m = 0;		//n^m�η�
		int L;		//����L������
		char answer[10];
		int flag = 1, max[101] = {0}, curr = 0;
		stack <Program>sp;
	
		cin >> L >> answer;
		for(int j = 1; j <= L; j++) 
		{
			char type, vir, str1[4], str2[4];
			cin.sync();
			//cin.getline(str,4);		//�������
			cin >> type;
			if(type != 'E')
			{
				cin >> vir >> str1 >> str2;
				curr++;
			}
			
			if(!flag)
				continue;
			
			if(type == 'F')
			{
				pra[j].x = vir;
				if(book[vir])		//�����ĸ�������﷨���� 
					flag = 0;
				else
					book[vir]++;		//��¼��ĸ 
	
				if(read_se( pra[j], str1, str2))		//�жϸ��Ӷ� 
				{
					
				}
				sp.push(pra[j]);					//��ջ 
			}
			else if(type == 'E')
			{
				if(sp.empty())		//�������ΪE��ջΪ��������﷨���� 
				{
					flag = 0;
					continue;
				}
				
				Program temp;
				temp = sp.top();
				sp.pop();
				if(!max[curr])
				{
					m += temp.o;		//m += o���ջ 
					if(temp.o != 0)
						max[curr]++;
					curr--;
				}
				book[temp.x]--;			//����x�������ļ�¼ 
			}
			
		}
		cout << "flag =  " << flag << ",";
		cout << "i = " << i << ",";
		cout << "answer = " << answer << ","; 
		cout << "m = " << m << endl;
		
		if(!flag || !sp.empty())
		{
			cout << "ERR" << endl;
			continue;
		}
		
		int k = 4, sum = 0;
		while(isdigit(answer[k]))
		{
			sum = sum*10 + answer[k]-'0';
			k++;
		}
		
		if(!m) 
		{
			if(answer[2] == '1')
				cout << "Yes\n"; 
			else
				cout << "No\n";
		}
		else
		{
			if(m == sum)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		
	}
	cout << "Holle world" << endl;
    return 0;
}



