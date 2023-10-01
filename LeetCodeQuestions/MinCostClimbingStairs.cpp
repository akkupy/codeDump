
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    // Normal Recursive Solution
    // int solve(vector<int> &cost, int n){
    //     if(n==1 || n==0)
    //         return cost[n];

    //     int ans= cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    //     return ans;
    // }

    // Recursion + Memoization (Top-Down)
    // int solve(vector<int> &cost, int n, vector<int> &dp){
    //     if(n==1 || n==0)
    //         return cost[n];
        
    //     if(dp[n]!=-1)
    //         return dp[n];

    //     dp[n]= cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));

    //     return dp[n];
    // }

    // Tabulation Method (Bottom-Up)
    // int solve(vector<int> &cost, int n){
    //     vector<int> dp(n);
    //     dp[0]= cost[0];
    //     dp[1]= cost[1];

    //     for(int i=2; i<n; i++){
    //         dp[i]= cost[i] +  min(dp[i-1], dp[i-2]);
    //     }

    //     return min(dp[n-1], dp[n-2]);

    // }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Normal Recursive Solution
        // return min(solve(cost, cost.size()-1), solve(cost, cost.size()-2));

        // Recursion + Memoization (Top-Down)
        // int size= cost.size();
        // vector<int> dp(size, -1);
        // return min(solve(cost, size-1, dp), solve(cost, size-2, dp));

        // Tabulation Method (Bottom-Up)
        // int size= cost.size();
        // return solve(cost, size);

        // Dp with space optimization
        int size= cost.size();

        int previousOne= cost[0];
        int previousTwo= cost[1];
        int curr;

        for(int i=2; i<size; i++){
            curr= cost[i] + min(previousOne, previousTwo);
            previousOne= previousTwo;
            previousTwo= curr;
        }

        return min(previousOne, previousTwo);

    }
};