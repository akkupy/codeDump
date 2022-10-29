import java.util.Scanner;
public class prime {
        public static void main(String args[]){
                int a , b=0;
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter a number :");
		a =  obj.nextInt();
                obj.close();
                if (a==0 || a==1)
                        System.out.println("Neither prime nor composite");
                for (int i=2;i<=a/2;i++){
                        if (a%i==0){
                                b = 1;
                                break;
                        }       
                }
                if (b==1)
                        System.out.println("It is Not Prime");
                else 
                        System.out.println("It is Prime");
        }
}

