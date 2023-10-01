class area_shapes {
    
    public void area(double a)
    {
        System.out.println("Area of circle is : "+(3.14*a*a));
    }
    public void area(int n,int m)
    {
        System.out.println("Area of Rectangle is : "+(n*m));
    }
    public double area(double c,double d)
    {
        return 0.5*c*d;
    }
}
class Main{   
    public static void main(String args[])
    {
        area_shapes obj = new area_shapes();
        obj.area(3.90);
        obj.area(33,75);
        double triangle_area=obj.area(45.7,7.9);
        System.out.println("Area of triangle is : "+triangle_area);
    }
}
