import java.util.Arrays;
// Not correct
public class Firstmissing_positive {
    public static void main(String[] args) {
        int[] arr={3,4,-1,1};
        int ans=cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(ans);
    }
    static int cyclicSort(int[] arr){
    for (int i = 0; i < arr.length; i++) {
        int element=arr[i];
        int chair=element-1;
        if(element<=0 || element>arr.length){
            arr[i]=arr.length+1;
            if(arr[chair]!=element){
                swap(arr,arr[chair],arr[i]);
                i--;
            }
        }
    }
        // Search in the array
        for (int j = 0; j < arr.length; j++) {
            if(arr[j]!=j+1){
                return j+1;
            }
        }
        return arr.length+1;
    }
    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
