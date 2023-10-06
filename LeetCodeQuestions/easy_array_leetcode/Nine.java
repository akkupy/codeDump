import java.util.ArrayList;
import java.util.Arrays;

public class Nine {
    public static void main(String[] args) {
        int[] nums={1,2,3,4,0};
        int[] index={0,1,2,3,0};
       
        int[] target = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            solve(target,nums[i],index[i]);
            
        }
        System.out.println(Arrays.toString(target));
        }
        public static void solve(int[] target,int value,int index){
            for (int i = target.length-1; i >index; i--) {
                target[i]=target[i-1];
            }
            target[index]=value;
        }
    }
