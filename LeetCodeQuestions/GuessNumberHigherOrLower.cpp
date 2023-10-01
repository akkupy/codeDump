
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

class Solution {
public:
    // Simple Recursion Solution
    // int solve(int start, int end){
    //     if(start>=end)
    //         return 0;
        
    //     int ans= INT_MAX;
    //     for(int i=start; i<=end; i++){
    //         ans= min(ans, i + max(solve(start, i-1), solve(i+1, end)));
    //     }
    //     return ans;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(int start, int end, vector<vector<int>>& dp){
    //     if(start>=end)
    //         return 0;
        
    //     if(dp[start][end]!=-1)
    //         return dp[start][end];

    //     int ans= INT_MAX;
    //     for(int i=start; i<=end; i++){
    //         ans= min(ans, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
    //     }

    //     dp[start][end]= ans;

    //     return dp[start][end];
    // }

    int solve(int n){

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int start=n-1; start>=1; start--){
            for(int end=start; end<=n; end++){
                if(start==end){
                    continue;
                }
                else{
                    int ans= INT_MAX;
                    for(int i=start; i<=end; i++){
                        ans= min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                    }
                    dp[start][end]= ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // Simple Recursive Solution
        // return solve(1, n);

        // Recursion + Memoization (Top-Down Approach)
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(1, n, dp);

        return solve(n);

    }
};








