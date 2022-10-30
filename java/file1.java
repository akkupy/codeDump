import java.io.*;
class file1
{
 public static void main(String args[])
 {
  try
  {
    FileReader f1= new FileReader("Hi.txt");
    BufferedReader b1=new BufferedReader(f1);
    int i=0;
    int j=1;
    String s =b1.readLine();
    while(s!=null)
    {
      System.out.print(j+". ");
      System.out.print(s); 
      s=b1.readLine();
      System.out.println();
      j++;
    }
  }
  catch(Exception e)
  {}
 }
}
