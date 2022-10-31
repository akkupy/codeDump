#include<stdio.h>

int main()

{

	int n,i,an,s,l,c;

	printf("Enter total number of blocks in the disk:");

	scanf("%d",&n);

	int a[n];

	for(i=0;i<n;i++)

	{

		a[i]=0;

	}

	printf("Enter number of blocks already allocated:");

	scanf("%d",&an);

	printf("Enter index of already allocated blocks:");

	for(i=0;i<an;i++)

	{

		scanf("%d",&s);

		a[s]=1;

	}

	do{

		printf("Enter starting and length of file:");

		scanf("%d%d",&s,&l);

		printf("Allocated blocks:\n");

		for(i=0;i<l;i++)

		{

			if(a[s]==0)

			{

				printf("-->%d\n",s);

				a[s++]=1;

			}

			else 

			{

				while(a[s]!=0)

				{

					printf("%d is already allocated\n",s);

					s++;

				}

				printf("-->%d\n",s);

				a[s++]=1;

			}

		}

		printf("\nDo you want to continue?(1.yes/0.No):");

		scanf("%d",&c);

	}while(c!=0);

	return 0;

}

Footer
