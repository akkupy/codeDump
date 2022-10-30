import java.util.*;
public class area_shapes {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.Circle/2.Rectangle/3.Triangle");
        System.out.println("Select an option(1/2/3) :");
        int a = sc.nextInt();
        area_shapes obj = new area_shapes();
        if (a==1) {
            System.out.println("Enter the radius :");
            int b =sc.nextInt();
            obj.area(b);
        }
        else if (a==2){
            System.out.println("Enter the length :");
            int b =sc.nextInt();
            System.out.println("Enter the breadth :");
            int c =sc.nextInt();
            obj.area(b,c);
        }
        else if (a==3) {
            System.out.println("Enter the base :");
            double b =sc.nextDouble();
            System.out.println("Enter the height :");
            double c =sc.nextDouble();
            obj.area(b,c);
        }
        else 
            System.out.println("Error");
        sc.close();
    }
    void area(int a)
    {
        System.out.println("Area of circle is:"+(3.14*a*a));
    }
    void area(int n,int m)
    {
        System.out.println("Area of Rectangle is:"+(n*m));
    }
    void area(double c,double d)
    {
        System.out.println("Area of triangle is:"+(0.5*c*d));
    }
}
