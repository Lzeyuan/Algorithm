#include <stdio.h>
#include <string.h>

int main()
{
	char a[51];
	int i, j, n;
	scanf("%d%s",&n,a);
	j = strlen(a);
	for(i = 0 ; i < j ; i++)
	{
		a[i] = (a[i] - 'a' + n)%26 + 'a'; 
		printf("%c",a[i]);
	}
} 
