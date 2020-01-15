#include <iostream>
#include <string>

using namespace std;

const int N = 101;

void Bshow(int p1, int p2, int p3, string &z)
{
	if(p3 == 1)
	{
		if(p1 == 3)
		{
			for(int i = z[0]-47; i < z[2]-49; i++)
				for(int j = 1; j <= p2; j++)
						cout << '*';
		}
		else
		{
			for(int i = z[0]-47; i < z[2]-49; i++)
				for(int j = 1; j <= p2; j++)
					cout << i;
		}
	}
	else
	{
		if(p1 == 3)
		{
			if(p1 == 3)
			{
				for(int i = z[2]-49; i < z[0]-47; i--)
					for(int j = 1; j <= p2; j++)
							cout << '*';
			}
		}
		else
		{
			for(int i = z[2]-49; i < z[0]-47; i--)
					for(int j = 1; j <= p2; j++)
						cout << j;
		}
	}
}

void Ashow(int p1, int p2, int p3, string &z)
{
	if(p3 == 1)
	{
		if(p1 == 1)
		{
			for(int i = z[0]+1; i < z[2]; i++)
			{
				if(i <= 'Z' && i >= 'A')
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i+32);
				}
					
				else
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i);
				}
			}
		}
		else if(p1 == 2)
		{
			for(int i = z[0]+1; i < z[2]; i++)
			{
				if(i <= 'z' && i >= 'a')
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i-32);
				}
				else
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i);
				}
			}
		}
		else if(p1 == 3)
		{
			for(int i = z[0]+1; i < z[2]; i++)
				for(int j = 1; j <= p2; j++)
					cout << '*';
		}
	}
	else if(p3 == 2)
	{
		if(p1 == 1)
		{
			for(int i = z[2] - 1; i > z[0]; i--)
			{
				if(i <= 'Z' && i >= 'A')
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i+32);
				}
					
				else
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i);
				}
			}
		}
		else if(p1 == 2)
		{
			//cout << "z[2]-1 = "  << z[2] - 1 << "z[0] = " << int(z[0]) << endl;
			for(int i = z[2] - 1; i > z[0]; i--)
			{
				if(i <= 'z' && i >= 'a')
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i-32);
				}
				else
				{
					for(int j = 1; j <= p2; j++)
						cout << char(i);
				}
			}
		}
		else if(p1 == 3)
		{
			for(int i = z[2] - 1; i > z[0]; i--)
				for(int j = 1; j <= p2; j++)
					cout << '*';
		}
	}
}

bool Al(char c)
{
	if(c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A')
		return 1;
	else
		return 0;
}	

bool Bl(char c)
{
	if(c <= '9' && c >= '0')
		return 1;
	else
		return 0;
}	

int main()
{
	int p1, p2, p3;
	string s, z;
	int i = 0;
	
	cin >> p1 >> p2 >> p3 >> s;
	
	
	
	do
	{
		z[0] = s[i];
		z[1] = s[i+1];
		z[2] = s[i+2];
		
		if(z[1] == '-' && z[0] < z[2])
		{
			if( Al(z[0]) && Al(z[2]) )
			{
				cout << z[0];
				Ashow(p1,p2,p3,z);
				//cout << z[2];
				i += 1;
				continue;
			}
			else if( Bl(z[0]) && Bl(z[2]) )
			{
				cout << z[0];
				Bshow(p1,p2,p3,z);
				cout << z[2];
				i += 1;
				//continue;
			}
		}
		
		cout << s[i];
		
	}while(i++,s[i] != '\0');
	
	
    return 0;
}



