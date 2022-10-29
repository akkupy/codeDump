import java.util.Scanner;
class Check
{
 public static void main(String args[])
 {Scanner sc=new Scanner(System.in);
  System.out.print("enter the no tobe checked");
  int n=sc.nextInt();
  if(n%2==0)
    System.out.println("EVEN");
  else
    System.out.println("ODD");
  sc.close();    

 }   
}