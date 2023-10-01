import java.util.*;
public class LeetLeetCode {
    public static void main(String[] args) {
        String s="leet2";
        char ch=ans(s, 2);
        System.out.println(ch);
    }
    public static char ans(String s, int k){
        Stack<String> stack=new Stack();
        Stack<Integer> counts=new Stack();
        String res="";
        int index=0;
        while(index<s.length()){
            if(Character.isDigit(s.charAt(index))){
                int count=0;
                while(Character.isDigit(s.charAt(index)) && index<s.length()-1){
                    count=10*count+(s.charAt(index)-'0');
                    index+=1;
                }
                counts.push(count);
                
                    stack.push(res);
                
                res="";
                for(int i=0; i<counts.pop(); i++){
                    res+=stack.pop();
                }
            }
            else{
                res+=s.charAt(index);
                index+=1;
            }
        }
        return res.charAt(k);

    }
}
