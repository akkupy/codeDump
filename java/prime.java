import java.util.Scanner;
class Prime
{
 public static void main(String arfgs[])
 {int n,i,flag=0;
  Scanner sc=new Scanner(System.in);
  System.out.println("enter the no");
  n=sc.nextInt();
  if(n==0 || n==1)
    System.out.println("not prime");
  else
  {for(i=2;i<=n/2;i++)
    {if(n%i==0)
       {flag=1;
        System.out.println("not prime");  
        break;
       }
       sc.close(); 
    }
  if(flag==0)
  System.out.println("prime");

}
 
  }
 }   
