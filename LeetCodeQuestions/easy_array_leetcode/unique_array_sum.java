import java.util.Arrays;

public class unique_array_sum {
    public static void main(String[] args) {
        int n=5;
        int[] arr=new int[n];
        arr=sumZero(n);
        System.out.println(Arrays.toString(args));
    }
  
        public static int[] sumZero(int n) {
            int k=1;
            int[] arr=new int[n];
            if(n%2!=0){
                arr[0]=0;
                for(int i=1;i<n;i++){
                    arr[i]=k;
                    k*=-1;
                   if(k<0){
                       k+=1;
                   }
                }
            }
            else{
                 for(int i=0;i<n;i++){
                    arr[i]=k;
                    k*=-1;
                   if(k<0){
                       k+=1;
                   }
                }
            }
            return arr;
        }
    }

