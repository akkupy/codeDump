/*Write a Java program to calculate the perimeter of different shapes
namely circle and rectangle using the concept of constructor
overloading.*/
import java.util.*;
public class perimeter_shapes {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of circle :");
        int a = sc.nextInt();
        System.out.println("Enter the length of rectangle :");
        int b = sc.nextInt();
        System.out.println("Enter the breadth of rectangle :");
        int c = sc.nextInt();
        perimeter_shapes obj=new perimeter_shapes(a);
        perimeter_shapes obj1=new perimeter_shapes(b,c);
        sc.close();
    }
    perimeter_shapes(int a)
    {
        System.out.println("Perimeter of circle is:"+(3.14*2*a));
    }
    perimeter_shapes(int n,int m)
    {
        int p=n+m;
        int t=2*p;
        System.out.println("Perimeter  of Rectangle is:"+t);
    }
} 

