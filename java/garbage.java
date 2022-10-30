public class garbage
{
    String name;
    public static void main(String[] args) 
    {
        garbage garb=new garbage();
        garb.name="Gayathri";
        garb=null;
        System.gc();
    }
    public void finalize()
    {
        System.out.println("Object is garbage collected");
    }
}
