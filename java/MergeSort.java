public class MergeSort {
	public static void main(String[] args) {
		System.out.println("hey hey hey!");
		int arr [] = {-1, 6, 7, 4, -3, 43};
		mergeSort(arr, 0, arr.length);
		    for(int i = 0; i<arr.length; i++){
			    System.out.println(arr[i]);
			}
	}
	public static void mergeSort(int arrIn[], int start, int end){
		if(end - start < 2){
			    return;
		}
		int mid = (start + end)/2;
		mergeSort(arrIn, start, mid);
		mergeSort(arrIn, mid, end);
		merge(arrIn, start, mid, end);
		
	}
		
	public static void merge(int arrIn[], int start, int mid, int end){
		    //Change the condition here and on line 33 for change in ascending or descending order
		    if(arrIn[mid-1]>arrIn[mid]){
		    	    return;
		    }
		    
		    int i = start;
		    int j = mid;
		    int temp[] = new int[end - start];
		    int tempIndex = 0;
		    
		    while(i<mid && j<end){
		    	    temp[tempIndex++] = arrIn[i] >= arrIn[j] ? arrIn[i++] : arrIn[j++];
		    	    
		    }
		    System.arraycopy(arrIn, i,arrIn, start+tempIndex, mid-i);
		    System.arraycopy(temp, 0, arrIn, start, tempIndex);
		    
	}
}
