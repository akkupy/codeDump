abstract class Shape
{
    void numberofSides(){}
}

class Rectangle extends Shape
{
    void numberofSides()
    {
        System.out.println("Rectangle has 4 sides.");
    }
}

class Triangle extends Shape
{
    void numberofSides()
    {
    System.out.println("Triangle has 3 sides.");
    }
}

class Hexagon extends Shape
{
    void numberofSides()
    {
    System.out.println("Hexagon has 6 sides.");
    }
}

public class Sides {
    public static void main(String[] args)
    {
    Rectangle r = new Rectangle();
    r.numberofSides();
    Triangle t = new Triangle();
    t.numberofSides();
    Hexagon h = new Hexagon();
    h.numberofSides();
    }
}
