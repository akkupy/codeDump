public class thread_oddeven {
	public static void main(String[] args) {
		oddthread o = new oddthread();
		eventhread et = new eventhread();

		o.start();
		try { 
			o.join();
		}
		catch(Exception e) {
			System.out.println(e);
		}

		et.start();
		try { 
			et.join();
		}

		catch(Exception e) {
			System.out.println(e);
		}
	}
}

class oddthread extends Thread {
	public void run() {
		try {
			System.out.print("Odd Numbers  : ");
			for(int i=1;i<=100;i+=2)
			{
				System.out.print(i+" ");
			}
			System.out.println();
		}
		catch(Exception e) {
			System.out.print(e);
		}
	}
}

class eventhread extends Thread {
	public void run() {
		try {
			System.out.print("Even Numbers : ");
			for(int i=2;i<=100;i+=2) {
				System.out.print(i+" ");
			}
			System.out.println();
		}
		catch(Exception e) {System.out.print(e);}
	}
}
