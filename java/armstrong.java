import java.util.*;
class armstrong
{
    public static void main(String args[])
    {
        int num,result=0,rem;
        System.out.println("enter the number:");
        Scanner sc=new Scanner(System.in);
        num=sc.nextInt();
        int temp=num;
        while(num>0)
        {
            rem=num%10;
            result=result+(rem*rem*rem);
            num=num/10;
        }
        if(result==temp)
        System.out.println("armstrong");
        else 
        System.out.println("not armstrong");
    }
}
