import java.io.*;

class quick_sort {

	static void swap(int[] arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	static int partition(int[] arr, int low, int high)
	{
		int pivot = arr[low];

		int i = (low + 1), j = high;

        while(i<j){
            while(arr[i]<=pivot && i<high) i++;
            while(arr[j]>pivot && j>low) j--;

            if(i<j) swap(arr,i,j);
        }
        swap(arr,low,j);
        return j;
		
	}

	
	static void quickSort(int[] arr, int low, int high)
	{
		if (low < high) {

			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	// To print array
	public static void printArr(int[] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

	
	public static void main(String[] args)
	{
		int[] arr = { 10, 7, 8, 9, 1, 5 };
		int N = arr.length;

		
		quickSort(arr, 0, N - 1);
		System.out.println("Sorted array:");
		printArr(arr);
	}
}
