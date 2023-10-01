import java.util.*;
public class reverseString {
   public static void main(String[] args) {
        char[] s={'h','e','l','l'};
        reverseString(s);

   } 
   
    public static void reverseString(char[] s) {
      int start=0;
        int end=s.length-1;
        while(start<end){
            swap(s,start,end);
            
            start++;
            end--;
        }
        System.out.println(Arrays.toString(s));
    }
    public static void swap(char[] arr,int start,int end){
       
            
           char temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
       
    }

}
