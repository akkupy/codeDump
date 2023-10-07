#include<stdio.h>
int main()
{
	int m,p,i,fn,np,pid,npg,j,c=0;
	printf("Enter total memory size:");
	scanf("%d",&m);
	printf("Enter page size:");
	scanf("%d",&p);
	fn=m/p;
	int a[fn][2];
	for(i=0;i<fn;i++)
	{
		a[i][0]=-1;
		a[i][1]=0;
	}
	printf("Enter total number of processes:");
	scanf("%d",&np);
	while(np!=0)
	{
		printf("Enter process number and number of pages needed:");\
		scanf("%d%d",&pid,&npg);
		printf("Enter frame numbers for pages of process %d:",pid);
		for(i=0;i<npg;i++)\
		{
			scanf("%d",&j);
			if(a[j][1]==0)
			{
				printf("--F[%d]\n",j);
				a[j][0]=i;
				a[j][1]=1;
				c++;
			}
			else
			{
				printf("\nFrames are already allocated\n");
				if (c==fn)
				{
					for(int k=0;k<fn;k++)
					{
						a[k][0]=-1;
						a[k][1]=0;
					}			
					c=0;
				}
				for(int k=j;k<fn;k++)
				{
				 if(a[k][1]==0)
				 {
				 	j=k;
				 	break;
				 }
				}
				printf("--F[%d]\n",j);
				a[j][0]=i;
				a[j][1]=1;
				c++;
			}
		}
		np--;
	}
	return 0;
}
