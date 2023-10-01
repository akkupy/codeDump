import java.util.Scanner;
public class GCD{
    public static void main(String[] args){
        int num1, num2;
        Scanner myobj = new Scanner(System.in);
        System.out.print("Enter first number: ");
        num1 = myobj.nextInt();

        System.out.print("Enter second number: ");
        num2 = myobj.nextInt();
        myobj.close()
        while(num1 != num2){
            if(num1>num2){
                num1 = num1-num2;
            }
            else{
                num2 = num2 - num1
            }

        }
        System.out.println("GCD of given numbers is: %d", num2);
    }
}