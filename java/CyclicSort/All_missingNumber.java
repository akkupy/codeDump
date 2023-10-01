import java.util.*;

public class All_missingNumber {
    public static void main(String[] args) {
        int[] arr={4,3,2,7,8,2,3,1};
        ArrayList<Integer> list=new ArrayList<>();
        list=CyclicSort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(list);
    }
    static ArrayList<Integer> CyclicSort(int[] arr){
        ArrayList<Integer> list=new ArrayList<>();
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

        //search for the All the missing Numbers
        for (int j = 0; j < arr.length; j++) {
            if(arr[j]!=j+1){
                    list.add(j+1);
            }
            
        }
        return list;

    }
    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
