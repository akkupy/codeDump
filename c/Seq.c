#include<stdio.h>

int main()

{

	int n,s,l,c,i,count;	printf("Enter total number of blocks in the disk:");

	scanf("%d",&n);

	int a[n];

	for(i=0;i<n;i++)

	{

		a[i]=0;

	}

	do{

		count=0;

		printf("Enter starting block and length of file:");

		scanf("%d%d",&s,&l);

		for(i=s;i<(s+l);i++)

		{

			if(a[i]==0)

			{

				count++;

			}

		}

		if(count==l)

		{

			for(i=s;i<(s+l);i++)

			{

				a[i]=1;

			}

			printf("File Allocated\n");

		}

		else

		{

			printf("File Not Allocated\n");

		}

		printf("Do you want to continue?(1.yes/0.No):");

		scanf("%d",&c);

	}while(c!=0);

	return 0;

}

Footer

© 2022 GitHub, Inc.

Footer navigation

Terms

Privacy

Security

Status

Docs
