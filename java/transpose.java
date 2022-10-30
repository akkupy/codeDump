import java.util.*;
class transpose
{
    public static void main(String args[])
    {
        int i,j;
        int a[][]=new int[20][20];
        int t[][]=new int[20][20];
        Scanner sc=new Scanner(System.in);
        System.out.println("enter numbr of rows:");
        int m=sc.nextInt();
        System.out.println("enter number of cloumns:");
        int n=sc.nextInt();
        System.out.println("enter the matrix:");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=sc.nextInt();
            }
        }
    
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                t[i][j]=a[j][i];
            }
        }
        System.out.println("transpose is:");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.println(t[i][j]+"\t");
            }
        }
        System.out.println("\n");
           
    }
}
