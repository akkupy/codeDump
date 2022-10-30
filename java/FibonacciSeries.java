import java.util.Scanner;
public class FibonacciSeries{
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n.");
        n= sc.nextInt();
        int a = 0;
        int b = 1;
        System.out.println("The fibonacci series till term number "+n+" is:");
        for(int i = 1; i <=(n+1)/2; i++){
            System.out.print(a+" ");
            if(n%2!=0 && i==(n+1)/2){
                break;
            }
            else{
                System.out.print(b+" ");
                a+=b;
                b+=a;
            }
            
        }
        sc.close();

    }
}
