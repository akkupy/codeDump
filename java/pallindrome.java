
import java.util.Scanner;
public class pallindrome {
	public static void main(String args[]) {
		int a,r,org,rev;
		rev=0;
		System.out.println("Enter a number : ");
		Scanner obj = new Scanner(System.in);
		a = obj.nextInt();
		obj.close();
		org = a;
		while (a>0) {
			r = a%10;
			rev = (rev*10)+r;
			a = a/10;
		}
		if (rev==org)
			System.out.println("Pallindrome");
		else
			System.out.println("Not pallindrome");
	}	
}
