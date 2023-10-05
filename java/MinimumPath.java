
import java.util.*;

class MinimumPath {
    // Function to calculate the minimum sum path in the matrix
    static int minSumPath(int n, int m, int[][] matrix) {
        // Initialize an array to store the previous row values
        int prev[] = new int[m];

        for (int i = 0; i < n; i++) {
            // Create a temporary array to store the current row values
            int temp[] = new int[m];

            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    temp[j] = matrix[i][j]; // If we're at the top-left cell, the minimum sum is its value
                else {
                    int up = matrix[i][j];
                    if (i > 0)
                        up += prev[j]; // Add the value from above if it's not out of bounds
                    else
                        up += (int) Math.pow(10, 9); // Add a large value if out of bounds in the up direction

                    int left = matrix[i][j];
                    if (j > 0)
                        left += temp[j - 1]; // Add the value from the left if it's not out of bounds
                    else
                        left += (int) Math.pow(10, 9); // Add a large value if out of bounds in the left direction

                    // Store the minimum of the two possible paths in the current cell
                    temp[j] = Math.min(up, left);
                }
            }
            // Update the previous row with the values of the current row
            prev = temp;
        }

        // The final result is stored in the last element of the previous row
        return prev[m - 1];
    }

    public static void main(String args[]) {
        // Define the matrix
        int matrix[][] = {
            {5, 9, 6},
            {11, 5, 2}
        };

        int n = matrix.length;
        int m = matrix[0].length;

        // Calculate and print the minimum sum path in the matrix
        System.out.println(minSumPath(n, m, matrix));
    }
}
