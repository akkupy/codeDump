class Customer {
    int amount=10000;
    synchronized void withdraw(int amount) {  
        System.out.println("Going to Withdraw...");
        if(this.amount<amount) {
            System.out.println("Going to Withdraw..");
            try {
                wait();
            }
            catch(Exception e) {
                System.out.println(e);
            }
        }
        this.amount-=amount;
        System.out.println("Withdraw completed");
    }
    synchronized void deposit(int amount) {
         System.out.println("Going to deposit");
         this.amount+=amount;
         System.out.println("Deposit completed..");
         notify();
    }
}

class MyThread1 extends Thread {
    Customer c;
    MyThread1(Customer c) {
        this.c=c;
    }
    public void run() {
       c.withdraw(15000);
    }
}

class MyThread2 extends Thread {
    Customer c;
    MyThread2(Customer c) {
      this.c=c;
    }
    public void run() {
       c.deposit(15000);
    }
}

public class banking {
    public static void main(String args[]) {
        Customer c= new Customer();
        MyThread1 t1=new MyThread1(c);
        MyThread2 t2=new MyThread2(c);
        t1.start();
        t2.start();
    }
}

