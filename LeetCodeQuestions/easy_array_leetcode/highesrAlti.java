import java.util.Arrays;

public class highesrAlti {
    public static void main(String[] args) {
        int[] gain={-5,1,5,0-7};
        int ans=largestAltitude(gain);
        System.out.println(ans);
    }
    public static int largestAltitude(int[] gain) {
        int[] arr=new int[gain.length+1];
        arr[0]=0;
        for(int i=1;i<gain.length+1;i++){
            arr[i]=arr[i-1]+gain[i-1];
        } 
        System.out.println(Arrays.toString(arr));
        int max=arr[0];
          for(int i=1;i<gain.length+1;i++){
              if(arr[i]>max){
                  max=arr[i];
              }
          }
          return max;
      }
}
