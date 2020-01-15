#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int book[10] = {0};
	
	for(int i = 123; i <= 333; i++)
	{
		memset(book,0,sizeof(book));
		int a = i*2;
		int b = i*3;
		int c = i;
		int flag = 0;
		
		while(c)
		{
			if(book[c%10]++ || c%10 == 0 )
			{
				flag = 1;
			}
			c /= 10;
		} 
		
		if(flag)
		{
			continue;
		}
		
		while(a)
		{
			if(book[a%10]++ || a%10 == 0)
			{
				flag = 1;
			}
			a /= 10;
		} 
		
		if(flag)
		{
			continue;
		}
		
		while(b)
		{
			if(book[b%10]++ || b%10 == 0)
			{
				flag = 1;
			}
			b /= 10;
		}
		
		if(flag)
		{
			continue;
		}
		
		cout << i << ' ' << i*2 << ' ' << i*3 << endl;
	}
	
    return 0;
}



