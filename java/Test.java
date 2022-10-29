class Single
{
 void msg1()
 {
  System.out.println("hello world");  
 }   
}
class Person extends Single
{void msg2()
{ 
    System.out.println("good morning");
}
}
class Teacher extends Single
{
 void msg3()
 {
   System.out.println("good evening");
 }   
}
class Test
{
 public static void main(String args[])
 {
  Teacher t=new Teacher();
  Person p=new Person();
  t.msg1();
  t.msg3();
  p.msg1();
  p.msg2(); 
 }   
}