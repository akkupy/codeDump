
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(int index, int buyOrSell, vector<int>& prices){
    //     if(index == prices.size())
    //         return 0;
        
    //     int profit= 0;
    //     // Buy Allowed
    //     if(buyOrSell){
    //         int buy= -prices[index]+solve(index+1, 0, prices);
    //         int skip= solve(index+1, 1, prices);
    //         profit= max(buy, skip);
    //     }
    //     else{
    //         int sell= prices[index]+solve(index+1, 1, prices);
    //         int skip= solve(index+1, 0, prices);
    //         profit= max(sell, skip);
    //     }
    //     return profit;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(int index, int buyOrSell, vector<int>& prices, vector<vector<int>>& dp){
    //     if(index == prices.size())
    //         return 0;
        
    //     if(dp[index][buyOrSell]!=-1)
    //         return dp[index][buyOrSell];

    //     int profit= 0;
    //     // Buy Allowed
    //     if(buyOrSell){
    //         int buy= -prices[index]+solve(index+1, 0, prices, dp);
    //         int skip= solve(index+1, 1, prices, dp);
    //         profit= max(buy, skip);
    //     }
    //     else{
    //         int sell= prices[index]+solve(index+1, 1, prices, dp);
    //         int skip= solve(index+1, 0, prices, dp);
    //         profit= max(sell, skip);
    //     }

    //     dp[index][buyOrSell]= profit;
    //     return dp[index][buyOrSell];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(vector<int>& prices){

    //     int n= prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2,0));

    //     for(int index= n-1; index>=0; index--){
    //         for(int buyOrSell= 0; buyOrSell<=1; buyOrSell++){
    //             int profit= 0;
    //             if(buyOrSell){
    //                 int buy= -prices[index] + dp[index+1][0];
    //                 int skip= dp[index+1][1];
    //                 profit= max(buy, skip);
    //             }
    //             else{
    //                 int sell= prices[index] + dp[index+1][1];
    //                 int skip= dp[index+1][0];
    //                 profit= max(sell, skip);
    //             }
    //             dp[index][buyOrSell]= profit;
    //         }
    //     }
    //     return dp[0][1];
    // }

    int solve(vector<int>& prices){

        int n= prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index= n-1; index>=0; index--){
            for(int buyOrSell= 0; buyOrSell<=1; buyOrSell++){
                int profit= 0;
                if(buyOrSell){
                    int buy= -prices[index] + next[0];
                    int skip= next[1];
                    profit= max(buy, skip);
                }
                else{
                    int sell= prices[index] + next[1];
                    int skip= next[0];
                    profit= max(sell, skip);
                }
                curr[buyOrSell]= profit;
            }
            next= curr;
        }
        return curr[1];
    }

    // DP with space optimization
    int maxProfit(vector<int>& prices) {

        // Simple Recursive Solution
        // return solve(0, 1, prices);

        // Recursion + Memoization (Top-Down Approach)
        // vector<vector<int>> dp(prices.size()+1, vector<int>(2,-1));
        // return solve(0, 1, prices, dp);

        // Tabulation Method (Bottom-Up Approach)
        // return solve(prices);

        return solve(prices);

    }
};






