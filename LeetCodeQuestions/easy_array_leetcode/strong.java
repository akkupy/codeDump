import java.util.*;
public class strong {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        int a=num;
        int k=0;
        int s=0;
        while(num>0){
                k=num%10;
                s+=fact(k);
                num=num/10;
        }
        if(a==s){
            System.out.println("Strong");
        }
        else{
            System.out.println("Not Strong");
        }

    }
    public static int fact(int num){
        int f=1;
        for(int i=1;i<=num;i++){
            f*=i;
        }
        return f;
    }
}
