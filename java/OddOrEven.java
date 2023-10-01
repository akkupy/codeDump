
import java.util.*;
public class Main
 {
      public static void main(String[] args) {
       //Taking input from the user
       Scanner sc =new Scanner(System.in);
       System.out.println("Enter the number");
       int number=sc.nextInt();

     //checking whether the number is even or odd
     if (number % 2 == 0)
              System.out.println(number + " is Even");
     else
              System.out.println(number + " is odd");
      }
 }
