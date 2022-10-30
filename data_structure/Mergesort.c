#include<stdio.h>

void merge(int a[],int l,int m,int r){

	int a1[m-l+1],a2[r-m],i,j,k;	for(i=0;i<(m-l+1);i++)

        	a1[i]=a[l+i];

        for(j=0;j<(r-m);j++){

		a2[j]=a[m+j+1];

	}

        i=0;j=0;k=l;

	while(i<m-l+1 && j<r-m){

		if(a1[i]<a2[j])

			a[k++]=a1[i++];

		else

			a[k++]=a2[j++];

		

	}

	while(i<m-l+1)

		a[k++]=a1[i++];

	while(j<r-m)

		a[k++]=a2[j++];

}

void mergesort(int a[],int l,int r){

	if(l<r){

		int m=(l+r)/2;

		mergesort(a,l,m);

		mergesort(a,m+1,r);

	        merge(a,l,m,r);

	}	

} 

int main(){

	int n,j;

	printf("Enter size of  array:\n");

	scanf("%d",&n);

	int a[n];

	printf("Enter values:\n");

	for(j=0;j<n;j++){

		scanf("%d",&a[j]);

	}

        mergesort(a,0,n);

	printf("Sorted Values:\n");

	for(j=0;j<n;j++){

		printf("%d\t",a[j]);

	}

	return 0;

}
