public class DuplicateNumber {
    public static void main(String[] args) {
       int[] arr={1,3,4,2,3};
       int ans=CyclicSort(arr);
       System.out.println(ans); 
    }
    static int CyclicSort(int[] arr){
        int i=0;
        while(i<arr.length){
            int correct=arr[i]-1;
            if(arr[i]!=arr[correct]){
                swap(arr,i,correct);
            }
            else{
                i++;
            }
        }

        // Search in the array
        for (int j = 0; j < arr.length; j++) {
            if(arr[j]!=j+1){
                return arr[j];
            }
        }
        return arr[arr.length];
    }
    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
