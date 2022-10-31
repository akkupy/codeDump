#include<stdio.h>

int a[50];

int main(){

	int n,j,size,l1,u1,l2,u2,i,k;	printf("Enter size of  array:\n");

	scanf("%d",&n);

	printf("Enter values:\n");

	for(i=0;i<n;i++) {

		scanf("%d",&a[i]);

	}

        size =1;

	while(size<n){

		l1=0;

		while(l1+size<n){

			u1=l1+size-1;

			l2=l1+size;

			u2=l2+size-1;

			if(u2>=n)

				u2=n-1;

			int a1[u1-l1],a2[u2-l2];

			for(i=0;i<=u1-l1;i++)

        			a1[i]=a[l1+i];

        		for(j=0;j<=u2-l2;j++)

				a2[j]=a[l2+j];	

			i=0;j=0;k=l1;

			while(i<=u1-l1 && j<=u2-l2){

				if(a1[i]<a2[j])

					a[k++]=a1[i++];

				else

					a[k++]=a2[j++];

		

			}

			while(i<=u1-l1)

				a[k++]=a1[i++];

			while(j<=u2-l2)

				a[k++]=a2[j++];

			l1=u2+1;

		}	

		size=size*2;

	}

	printf("Sorted Values:\n");

	for(j=0;j<n;j++){

		printf("%d\t",a[j]);

	}

	return 0;

}

Footer

© 2022 GitHub, Inc.

Footer navigation

Ter
