
// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(int n){
    //     if(n<=1)
    //         return 1;

    //     int ans= 0;
    //     for(int i=1; i<=n; i++){
    //         ans+= solve(i-1) * solve(n-i);
    //     }
    //     return ans;
    // }

    // int solve(int n, vector<int>& dp){
    //     if(n<=1)
    //         return 1;

    //     if(dp[n]!=-1)
    //         return dp[n];

    //     int ans= 0;
    //     // current root node
    //     for(int i=1; i<=n; i++){
    //         ans+= solve(i-1, dp) * solve(n-i, dp);
    //     }

    //     dp[n]= ans;

    //     return dp[n];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(int n){
    //     vector<int> dp(n+1, 0);
    //     dp[0]= 1;
    //     dp[1]= 1;

    //     // number of nodes
    //     for(int i=2; i<=n; i++){
    //         // current root node
    //         for(int j=1; j<=i; j++){
    //             dp[i]+= dp[j-1] * dp[i-j];
    //         }
    //     }

    //     return dp[n];
    // }

    int numTrees(int n) {
        // Simple Recursive Solution
        // return solve(n);

        // Recursion + Memoization (Top-Down Approach)
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        // Tabulation Method (Bottom-Up Approach)
        // return solve(n);

        long long ans =1;
        for(int i=n+1;i<=2*n;i++){
            ans = ans*i/(i-n);
        }
        return ans/(n+1);
    }
};










