
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
public:
    long long modValue= 1e9+7;
    // Simple Recursive Solution
    // int solve(int n, int k, int target){
    //     if(target<0)
    //         return 0;
    //     if(n==0 && target!=0)
    //         return 0;
    //     if(n!=0 && target==0)
    //         return 0;
    //     if(n==0 && target==0)
    //         return 1;

    //     long long ans= 0;
    //     for(int i=1; i<=k; i++){
    //         ans= (ans%modValue + solve(n-1, k, target-i)%modValue)%modValue;
    //     }

    //     return (int)ans;

    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(int n, int k, int target, vector<vector<int>>& dp){
    //     if(target<0)
    //         return 0;
    //     if(n==0 && target!=0)
    //         return 0;
    //     if(n!=0 && target==0)
    //         return 0;
    //     if(n==0 && target==0)
    //         return 1;

    //     if(dp[n][target]!=-1)
    //         return dp[n][target];

    //     long long ans= 0;
    //     for(int i=1; i<=k; i++){
    //         ans= (ans%modValue + solve(n-1, k, target-i, dp)%modValue)%modValue;
    //     }

    //     dp[n][target]= (int)ans;

    //     return dp[n][target];

    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(int n, int k, int target){
    //     vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    //     dp[0][0]= 1;

    //     for(int dice=1; dice<=n; dice++){
    //         for(int t=1; t<=target; t++){
    //             long long ans= 0;
    //             for(int i=1; i<=k; i++){
    //                 if(t-i>=0)
    //                     ans= (ans%modValue + (dp[dice-1][t-i])%modValue)%modValue;
    //             }
    //             dp[dice][t]= (int)ans;
    //         }
    //     }
    //     return dp[n][target];
    // }

    int solve(int n, int k, int target){

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0]= 1;

        for(int dice=1; dice<=n; dice++){
            for(int t=1; t<=target; t++){
                long long ans= 0;
                for(int i=1; i<=k; i++){
                    if(t-i>=0)
                        ans= (ans%modValue + (prev[t-i])%modValue)%modValue;
                }
                curr[t]= (int)ans;
            }
            prev= curr;
        }
        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // Simple Recursive Solution
        // return solve(n, k, target);
        
        // Recursion + Memoization (Top-Down Approach)
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solve(n, k, target, dp);

        return solve(n, k, target);

    }
};









