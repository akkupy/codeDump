import java.util.*;
class Employee
{

    void display()
    {

         System.out.println("Name of class is Employee.");

    }

   void calcSalary()
    {

        System.out.println("Salary of Employee is 10000");

    }

}

class Engineer extends Employee
{

    void calcSalary()
    {
        super.calcSalary();
        System.out.println("Salary of Engineer is 20000");

    }

}
class Employees
{

     public static void main(String args[])
     {

     Engineer e = new Engineer();
     e.display();
     e.calcSalary();

     }

}
