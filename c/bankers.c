#include<stdio.h>

int main()
{
	int r,c,min=-1,s,ct;
	printf("Enter number of processes:");
	scanf("%d",&r);
	int p[r];
	for(int i=1;i<=r;i++)
	{
		p[i]=0;
	}
	printf("Enter number of resources:");
	scanf("%d",&c);

	int max[r][c];
	printf("Enter max.number of resources required for each process:\n");
	for( int i=1;i<=r;i++)
	{
		printf("P[%d]:\n",i);
		for(int j=1;j<=c;j++)
		{
			printf("\tR[%d]:",j);
			scanf("%d",&max[i][j]);
		}
	}

	int allo[r][c];
	printf("Enter number of  resources allocated for each process:\n");
	for( int i=1;i<=r;i++)
	{
		printf("P[%d]:\n",i);
		for(int j=1;j<=c;j++)
		{
			printf("\tR[%d]:",j);
			scanf("%d",&allo[i][j]);
		}
	}

	int need[r][c];
	for( int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			need[i][j]=max[i][j]-allo[i][j];
		}
	} 

	int avl[1][c];
	printf("Enter number of  available resources:\n");
	{
	  for( int j=1;j<=c;j++)
	  {
	   	scanf("%d",&avl[1][j]);	
	  }
	}
	
	for(int i=1;i<=r;i++)
	{
		if(p[i]!=1)
		{
			ct=0;
			for(int j=1;j<=c;j++)
			{
				if(need[i][j]<=avl[1][j])
				{
					ct=ct+1;
				}
				else
				{
					break;
				}
			}
			if(ct==c)
			{
				p[i]=1;
                 printf("P[%d]\t",i);
				for(int j=1;j<=c;j++)
				{
					avl[1][j]+=allo[i][j];
				}
				i=0;
			}
		}
	}
	for(int i=1;i<=r;i++)
	{
		if(p[i]==1)
		{
			continue;
		}	
		else
		{
			printf("\n Not safe");
			return 0;
		}
	}
	printf("\nSafe");
	return 0;
}
