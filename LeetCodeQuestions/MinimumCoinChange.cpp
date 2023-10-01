
// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    // Recursive TLE Solution
    // int solve(vector<int> &coins, int amount){
    //     if(amount == 0)
    //         return 0;
    //     if(amount<0)
    //         return INT_MAX;

    //     int mini= INT_MAX;
    //     for(auto i : coins){
    //         int ans= solve(coins, amount - i);
    //         if(ans!=INT_MAX){
    //             mini= min(mini, 1+ans);
    //         }
    //     }

    //     return mini;
    // }

    // Recursion + Memoization - (Top-Down Approach)
    // int solve(vector<int> &coins, int amount, vector<int> &dp){
    //     if(amount == 0)
    //         return 0;
    //     if(amount<0)
    //         return INT_MAX;

    //     if(dp[amount]!=-1)
    //         return dp[amount];

    //     int mini= INT_MAX;
    //     for(auto i : coins){
    //         int ans= solve(coins, amount-i, dp);
    //         if(ans!=INT_MAX)
    //             mini= min(mini, 1+ans);
    //     }

    //     dp[amount]= mini;

    //     return mini;
        
    // }

    // Tabulation Method - (Bottom-Up Approach)
    int solve(vector<int>& coins, int amount){
        int n= coins.size();
        vector<int> dp(amount+1, INT_MAX);

        dp[0]= 0;

        for(int i=0; i<=amount; i++){
            for(auto j : coins){
                if(i-j>=0 && dp[i-j]!=INT_MAX){
                    dp[i]= min(dp[i], 1+ dp[i-j]);
                }
            }
        }
        
        if(dp[amount]==INT_MAX)
            return -1;
        else 
            return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Recursive TLE Solution
        // int ans= solve(coins, amount);
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;

        // Recursion + Memoization - (Top-Down Approach)
        // int n= coins.size();
        // vector<int> dp(amount+1, -1);
        // int ans= solve(coins, amount, dp);
        // if(ans==INT_MAX)
        //     return -1;
        // else
        //     return ans;

        // Tabulation Method - (Bottom-Up Approach)
        return solve(coins, amount);

    }
};