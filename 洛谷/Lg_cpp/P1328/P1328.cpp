#include  <iostream>

using namespace std;

int power[6][3]={{0},
{3,4},
{1,4},
{2,5},
{3,5},
{1,2},
};



int main()
{
	int n, na, nb;
	int a[201] = {0}, b[201] = {0};
	
	cin >> n >> na >> nb;
	
	for (int i = 0; i < na; i++)
	{
		cin >> a[i];
		a[i]++;
	}
	
	for (int i = 0; i < nb; i++)
	{
		cin >> b[i];
		b[i]++;
	}
	
	//—≠ª∑∂”¡–
	int fa, fb, ta, tb;
	fa = fb = ta = tb =0; 
	
	//score
	int scorea = 0, scoreb = 0; 
	
	for(int i = 0; i < n; i++)
	{
		//cout << "a = " << a[i%na] << "," << "b = " << b[i%nb] << endl;
		if (a[i%na] != b[i%nb])
		{
			for(int j = 0; j < 2; j++)
			{
				if(power[a[i%na]][j] == b[i%nb])
				{
					scorea++;
					break;
				}
				if(j)
				{
					scoreb++;
				}
			}
		}
	}
	cout << scorea << ' ' << scoreb;
    return 0;
}

