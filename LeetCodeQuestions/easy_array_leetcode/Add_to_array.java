import java.util.*;

public class Add_to_array {
    public static void main(String[] args) {
        int[] num={9,9,9,9,9,9,9,9,9,9};
        int k=1;
        ArrayList<Integer> list=new ArrayList<>();
        list=addToArrayForm(num, k);
        System.out.println(list);
    }
    public static ArrayList<Integer> addToArrayForm(int[] num, int k) {
        ArrayList<Integer> list=new ArrayList<>();
        ArrayList<Integer> revlist=new ArrayList<>();
        String str="";
        for(int i=0;i<num.length;i++){
            str+=num[i];
        }
      
         int sum=Integer.parseInt(str);
   
        sum+=k;
       
        int number=0;
        int n=(int)(Math.log10(sum))+1;
        for(int i=0;i<n;i++){
            number=sum%10;
            list.add(number);
            sum/=10;
        }
        for(int i=list.size()-1;i>=0;i--){
            revlist.add(list.get(i));
        }
        return revlist;
    }
}
