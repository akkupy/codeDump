import java.util.*;
public class lucky_number {
    public static void main(String[] args) {
        ArrayList<Integer> mat=new ArrayList<>();
        int[][] arr={{1,2,3},
                    {14,5,6},
                    {67,38,9}};
        for (int i = 0; i < arr.length; i++) {
            int minIndex=0;
            int min=99999999;
            for (int j = 0; j < arr[i].length; j++) {
                if(min>arr[i][j]){
                    min=arr[i][j];
                    minIndex=j;
                }
            }
            boolean isTrue=true;
            for (int j = 0; j < arr.length; j++) {
                if(arr[i][minIndex]<arr[j][minIndex]){
                    isTrue=false;
                    break;
                }
               
                    
                }
                if(isTrue){
                    mat.add(arr[i][minIndex]);
            }
          
        }
        System.out.println(mat);
    }
}
