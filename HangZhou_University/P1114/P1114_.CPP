#include <stdio.h>
#include <string.h>
int v[50005],w[10005],f[10005];
int min(int x,int y)
{
	return x > y ? y:x;
}
int main()
{
	int n,a,b,c,d,i,j;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			memset(f,50005,10010*sizeof(int));
			f[0]=0;
			scanf("%d%d",&a,&b);
			c=b-a;
			scanf("%d",&d);
			for(i=0;i<d;i++)
			{
                scanf("%d%d",&v[i],&w[i]);
				for(j=w[i];j<=c;j++)
				    f[j] = min(f[j], f[j-w[i]]+v[i]);     
                for(j = 0;j <= c; j++)
                    printf("%3d", f[j]);
                printf("\n");
			}
		    if(f[c]!=f[10005])
            	printf("The minimum amount of money in the piggy-bank is%d.\n",f[c]);
        	else
            	printf("This is impossible.\n");
		}
	}
	return 0;
}