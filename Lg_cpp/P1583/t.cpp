#include <iostream>
#include<algorithm>

using namespace std;

typedef struct{
	int number;
	int w;
}Friend;

bool cmp(Friend f1, Friend f2)
{
	if(f1.w != f2.w)
		return f1.w > f2.w;
	return f1.number > f2.number; 
} 

int main()
{
	Friend f[5] = {{1,5},{2,2},{3,9},{4,11},{5,2}};
	
	cout << "ÅÅĞòÇ°£º" << endl;
	for(int i = 0 ; i < 5; i++)
	{
		cout << f[i].number << ":" << f[i].w << " ";
	}
	cout << "\n================" << endl;
	
	sort(f,f+5,cmp);
	
	cout << "ÅÅĞòºó£º" << endl;
	for(int i = 0 ; i < 5; i++)
	{
		cout << f[i].number << ":" << f[i].w << " ";
	}
	cout << "\n================" << endl;
	
    return 0;
}



