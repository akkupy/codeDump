#include<stdio.h>
int partition(int [], int, int);
void qsort(int [], int, int);
void swap(int *, int *);
void print(int [],int);
int main() {
	int n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,0,n-1);
	print(a,n);
	return 0;
}

void qsort(int a[], int l, int r ) { 
	int x;
	if(l<r) {
		x = partition(a,l,r);
		qsort(a,l,x-1);
		qsort(a,x+1,r);
	}
}

int partition(int a[],int l, int r) {
	int key = a[l];
	int i=l+1,j=r;
	while(i<j) {
		while(a[i]<=key && i<r)
			i++;
		while(a[j]>key && j>l)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[l],&a[j]);
	return j;
}

void swap(int *p, int *q) {
	int temp = *p;
	*p=*q;
	*q=temp;
}


void print(int a[], int n) {
	printf("The Sorted Array is ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
