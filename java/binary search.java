import java.util.*;
class binarysearch
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		binarysearch bs = new binarysearch();
		System.out.print("Enter the size:");
		int n=sc.nextInt();
		int[] A = new int[n];
		System.out.print("Enter the elements:");
		for(int i=0;i<n;i++)
				A[i] = sc.nextInt();
		System.out.print("Enter the item to be searched:");
		int item = sc.nextInt();	
		int k = bs.Binaryser(A,n,item);
		if(k!=0)
			System.out.println(item+" is found at position "+k);	
		else
			System.out.println("Element "+item+" not in the list");

	}

	int Binaryser(int A[], int n, int item)
	{
		int beg=0,end=n-1,mid;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			if(A[mid]==item)
			{
				return(mid+1);
			}
			else if(item>A[mid])
			{
				beg=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		return 0;
	}

}
