public class MultiThreading extends Thread {
    public void run(){
        try {
            System.out.println("Thread is: "+Thread.currentThread().getId()+" "+Thread.currentThread().getName());
        } catch (Exception e) {
            System.out.println("Exception is:"+e);
        }
    }
}
