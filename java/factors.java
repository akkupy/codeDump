import java.util.Scanner;
public class factors {
        public static void main(String args[]) {
                int n;
		Scanner obj =  new Scanner(System.in);
		System.out.println("Enter the number : ");
		n = obj.nextInt();
                obj.close();
                System.out.println("Factors of "+ n +" are ");
                for (int i = 1;i<=n;i++) {
                        if (n%i==0)
                                System.out.println(i);
                }
        }
}


