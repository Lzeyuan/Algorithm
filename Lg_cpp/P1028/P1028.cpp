#include <stdio.h>

int add(int a,int *max)
{
	int i;
	for( i = 0; i <= a/2; i++)
	{
		if( a/2 == 0)
			(*max)++;
		else
			add(i,max);
	}
}


int main()
{
	int i, j, input, max = 0;
	
	scanf("%d",&input);
	
	add(input,&max);
	
	printf("%d",max);
			
	return 0;
} 
