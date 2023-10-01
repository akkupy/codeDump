import java.util.Random;

class Square extends Thread{
    int x;
    Square(int n){
        x = n;
    }
    public void run(){
        int sqr = x * x;
        System.out.println("Square of " + x + " = " + sqr );
    }
}

class Cube extends Thread{
    int x;
    Cube(int n){
        x = n;
    }
    public void run(){
        int cub = x * x * x;
        System.out.println("Cube of " + x + " = " + cub );
    }
}
class Number extends Thread{
    public void run(){
        Random random = new Random();
        for(int i =0; i<10; i++){
            int randomInteger = random.nextInt(100);
            System.out.println("Random Integer generated : " + randomInteger);
            if(randomInteger % 2 == 0){
                Square s = new Square(randomInteger);
                s.start();
            }
            else{
                Cube c = new Cube(randomInteger);
                c.start();
            }

            try {
                Thread.sleep(1000);
            // This thread generates random number 10 times
            // between 1 to 100 for every 1 second. The generated
            // random number is then passed as argument to
            // Square and Cube threads.
            // Output varies each time a program is executed.
            } catch (InterruptedException ex) {
                System.out.println(ex);
            }
        }
    }
}
public class threads {
    public static void main(String args[]) {
        Number n = new Number();
        n.start();
    }
}
