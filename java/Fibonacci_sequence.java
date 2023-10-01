public class Fibonacci {
    public static void main(String[] args) {
        int n = 10; // The number of Fibonacci terms to generate
        long[] fibonacciSeries = new long[n];

        // Initialize the first two terms
        fibonacciSeries[0] = 0;
        fibonacciSeries[1] = 1;

        // Generate the Fibonacci sequence
        for (int i = 2; i < n; i++) {
            fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
        }

        // Print the Fibonacci sequence
        System.out.println("Fibonacci Sequence (First " + n + " terms):");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciSeries[i] + " ");
        }
    }
}
