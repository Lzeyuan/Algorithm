/*
	F y 10 n	处理变量的两个赋值！ 
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

int read_se(Program &p, char *c1, char *c2)		//判断 
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
	
	cin >> t;		//有n个程序
	
	for( int i = 1; i <= t; i++ )		//循环判断n次 
	{
		int book[128] = {0};		//记录重名 
		Program pra[MAXSIZE + 1];
		int m = 0;		//n^m次方
		int L;		//读入L行数据
		char answer[10];
		int flag = 1, max[101] = {0}, curr = 0;
		stack <Program>sp;
	
		cin >> L >> answer;
		for(int j = 1; j <= L; j++) 
		{
			char type, vir, str1[4], str2[4];
			cin.sync();
			//cin.getline(str,4);		//读入程序
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
				if(book[vir])		//如果字母重用则语法错误 
					flag = 0;
				else
					book[vir]++;		//记录字母 
	
				if(read_se( pra[j], str1, str2))		//判断复杂度 
				{
					
				}
				sp.push(pra[j]);					//进栈 
			}
			else if(type == 'E')
			{
				if(sp.empty())		//如果读入为E，栈为空则表明语法错误 
				{
					flag = 0;
					continue;
				}
				
				Program temp;
				temp = sp.top();
				sp.pop();
				if(!max[curr])
				{
					m += temp.o;		//m += o后出栈 
					if(temp.o != 0)
						max[curr]++;
					curr--;
				}
				book[temp.x]--;			//撤销x变量名的记录 
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



