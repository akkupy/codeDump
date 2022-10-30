import java.util.*;
class quicksort
{
	
public static void main(String[] args)
{
	quicksort q = new quicksort();
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the number of element in the array : ");
	int n = sc.nextInt();
	int[] a = new int[n];
	System.out.print("Enter the array elements : ");
	for(int i=0;i<n;i++)
		a[i]=sc.nextInt();
	q.qsort(a,0,n-1);
	q.print(a,n);
}

void qsort(int a[], int l, int r )
{ 
	int x;
	if(l<r)
	{
		x = partition(a,l,r);
		qsort(a,l,x-1);
		qsort(a,x+1,r);
	}
}

int partition(int a[],int l, int r)
{
	int key = a[l];
	int i=l+1,j=r;
	while(i<j)
	{
		while(a[i]<=key && i<r)
			i++;
		while(a[j]>key && j>l)
			j--;
		if(i<j)
			{
			int temp = a[i];
			a[i]=a[j];
			a[j]=temp;
			}
	}
	int temp = a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}


void print(int a[], int n)
{
	System.out.print("The Sorted Array is ");
	for(int i=0;i<n;i++)
		System.out.format("%d ",a[i]);
	System.out.println();
}
}
