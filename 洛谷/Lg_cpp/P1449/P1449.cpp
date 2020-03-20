#include <iostream>
#include <cstdio> 
#include <cctype>
#include <cstring>

using namespace std;

typedef struct Tree
{
	char c;
	int elem;
	struct Tree *lchild, *rchild, *root;
}*Bitree ,Btree;

int sign(char c)
{
	if(c == '-' || c == '+' || c == '*' || c == '/')
		return 1;
	else
		return 0;
}

int preTree(Bitree T)
{
	if(T)
	{		
		if (!T->elem)
		{
			if (T->c == '+')
			{
				int sum = preTree(T->lchild) + preTree(T->rchild);
				return sum;
			}
			else if (T->c == '-')
			{
				int sum =  preTree(T->rchild) - preTree(T->lchild);
				return sum;
			}
			else if (T->c == '*')
			{
				int sum =  preTree(T->lchild) * preTree(T->rchild);
				return sum;
			}
			else if (T->c == '/')
			{
				int sum = preTree(T->rchild) / preTree(T->lchild);
				return sum;
			}
		}
		else
		{
			return T->elem;
		}
	}
	return 0;
}

void check(Bitree *T)
{
	if(*T)
		while( (*T)->lchild != NULL && (*T)->rchild != NULL && (*T)->root != NULL)
			*T = (*T)->root;
}



int main()
{
	Bitree T, root;
	
	int i = 0;
	char str[101];
	
	cin.getline(str,101);

	while(str[i] != '\0')
		i++;
	i--;
	
	root= new Btree;
	root->c = str[--i];
	--i;
	root->elem = 0;
	root->lchild = 0;
	root->rchild = 0;
	root->root = 0;
	T = root;
	
	
	while(i >= 0)
	{
		Bitree t;
		t = new Btree;
		
		t->elem = 0;
		t->c = '\0';
		t->lchild = 0;
		t->rchild = 0;
		t->root = T;
		
		if( isdigit(str[i]) )
		{
			int temp = str[i] - 48;
			int t2 = 10;
			while (i-1 >= 0 && isdigit(str[i-1]))
			{
				
				temp = temp + (str[i-1] - 48)*t2;
				t2 *= 10;
				i--;
			}

			t->elem = temp;
			
			
			if(T->lchild == NULL)
			{
				T->lchild = t;
			}
			else
			{
				T->rchild = t;
			}
			i--;
			check(&T); 
			continue;
		}
		else if( sign(str[i]) )
		{
			t->c = str[i];
			
			if(T->lchild == NULL)
			{
				T->lchild = t;
				T = t;
			}
			else
			{
				T->rchild = t;
				T = t;
			}
			i--;
			check(&T); 
			continue;
		}
		i--;
	}

	cout << preTree(root);
	
    return 0;
}



