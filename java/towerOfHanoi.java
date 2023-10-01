public class TowerOfHanoi
{
static void towrOfHanoi(int disk, char fromPole, char toPole, char auxPole)
{
    if (disk == 1)
    {
          System.out.println("Moving disk 1 from pole " + fromPole + " to pole " + toPole);
           return;
     }
     towrOfHanoi(disk - 1, fromPole, auxPole, toPole);
     
      System.out.println("Moving disk " + disk + " from pole " + fromPole + " to pole " + toPole);

      towrOfHanoi(disk - 1, auxPole, toPole, fromPole);
}
       public static void main(String argvs[])
       {
               int disks = 3; 
               char first = 'A'; 
               char second = 'B'; 
               char third = 'C'; 
               towrOfHanoi( disks, first, third, second );
      }
} 
