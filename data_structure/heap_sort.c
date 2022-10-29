#include <stdio.h>
#define MAX 10
void RestoreHeapUp(int *,int);
void RestoreHeapDown(int*,int,int);

int main() {
	int Heap[MAX],n,i,j;
	
	printf("\n Enter the number of elements : ");
	scanf("%d",&n);
	printf("\n Enter the elements : ");
	for(i=1;i<=n;i++) {
		scanf("%d",&Heap[i]);
		RestoreHeapUp(Heap, i); 
	}

	j=n;
	for(i=1;i<=j;i++) {
		int temp;
		temp=Heap[1];
		Heap[1]= Heap[n];
		Heap[n]=temp;
		n = n-1; 
		RestoreHeapDown(Heap,1,n); 
	}
	n=j;
	printf("\n The sorted elements are: ");
	for(i=1;i<=n;i++)
		printf("%4d",Heap[i]);
	return 0;
	}

void RestoreHeapUp(int *Heap,int index) {
	int val = Heap[index];
	while( (index>1) && (Heap[index/2] < val) ) {
		Heap[index]=Heap[index/2];
		index /= 2;
	}
	Heap[index]=val;
}

void RestoreHeapDown(int *Heap,int index,int n) {
	int val = Heap[index];
	int j=index*2;
	while(j<=n) {
		if( (j<n) && (Heap[j] < Heap[j+1]))
			j++;
		if(Heap[j] < Heap[j/2]) 
			break;
		Heap[j/2]=Heap[j];
		j=j*2;
	}
	Heap[j/2]=val;
}