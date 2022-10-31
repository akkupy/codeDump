import java.util.*;
public class SpecialNum{
  public static int fact(int x){
    if(x == 0 || x == 1){
      return 1;
    
    }
    return x*(fact(x-1));
  }
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    int x, num, digit, sum = 0;
    System.out.print("Enter the number: ");
    x = sc.nextInt();
    num = x;
    while(num > 0){
      digit = num%10;
      sum += fact(digit);
      num = num/10;
    }
    if(sum == x){
      System.out.println(x + " is a Special number.");
    }else{
      System.out.println(x + " is not a Special number.");
    }
  
  
  }
}
