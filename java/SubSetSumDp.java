class SubSetSumDp {

    public static boolean isSubsetSum(int[] set, int targetSum) {
        int n = set.length;
        boolean[][] dp = new boolean[n + 1][targetSum + 1];

        // Base cases
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        // DP calculation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= targetSum; j++) {
                if (j < set[i - 1]) {
                    // If current element is greater than the target sum, ignore it
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Include or exclude the current element
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
                }
            }
        }

        // Return the result
        return dp[n][targetSum];
    }

    public static void main(String[] args) {
        int[] set = {3, 34, 4, 12, 5, 2};
        int targetSum = 60;

        boolean result = isSubsetSum(set, targetSum);
        System.out.println("Subset with sum " + targetSum + " exists: " + result);
    }
}
