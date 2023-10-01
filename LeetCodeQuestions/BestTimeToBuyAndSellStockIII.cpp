
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    // Simple Recursive Solution (Top-Down Approach)
    // int solve(int index, int buyOrSell, vector<int>& prices, int maxSell){
    //     if(index == prices.size())
    //         return 0;
        
    //     if(maxSell==2)
    //         return 0;

    //     int profit= 0;
    //     // Buy Allowed
    //     if(buyOrSell){
    //         int buy= -prices[index]+solve(index+1, 0, prices, maxSell);
    //         int skip= solve(index+1, 1, prices, maxSell);
    //         profit= max(buy, skip);
    //     }
    //     else{
    //         int sell= prices[index]+solve(index+1, 1, prices, maxSell+1);
    //         int skip= solve(index+1, 0, prices, maxSell);
    //         profit= max(sell, skip);
    //     }

    //     return profit;
    // }

    // int solve(int index, int buyOrSell, vector<int>& prices, int maxSell, vector<vector<vector<int>>>& dp){
    //     if(index == prices.size())
    //         return 0;
        
    //     if(dp[index][buyOrSell][maxSell]!=-1)
    //         return dp[index][buyOrSell][maxSell];

    //     if(maxSell==2)
    //         return 0;

    //     int profit= 0;
    //     // Buy Allowed
    //     if(buyOrSell){
    //         int buy= -prices[index]+solve(index+1, 0, prices, maxSell, dp);
    //         int skip= solve(index+1, 1, prices, maxSell, dp);
    //         profit= max(buy, skip);
    //     }
    //     else{
    //         int sell= prices[index]+solve(index+1, 1, prices, maxSell+1, dp);
    //         int skip= solve(index+1, 0, prices, maxSell, dp);
    //         profit= max(sell, skip);
    //     }

    //     dp[index][buyOrSell][maxSell]= profit;

    //     return dp[index][buyOrSell][maxSell];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(vector<int>& prices){
    //     int n= prices.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    //     for(int index=n-1; index>=0; index--){
    //         for(int buyOrSell=0; buyOrSell<=1; buyOrSell++){
    //             for(int maxSell=1; maxSell>=0; maxSell--){
    //                 int profit= 0;
    //                 // Buy Allowed
    //                 if(buyOrSell){
    //                     int buy= -prices[index]+dp[index+1][0][maxSell];
    //                     int skip= dp[index+1][1][maxSell];
    //                     profit= max(buy, skip);
    //                 }
    //                 else{
    //                     int sell= prices[index]+dp[index+1][1][maxSell+1];
    //                     int skip= dp[index+1][0][maxSell];
    //                     profit= max(sell, skip);
    //                 }
    //                 dp[index][buyOrSell][maxSell]= profit;
    //             }
    //         }
    //     }
        
    //     return dp[0][1][0];
    // }

    int solve(vector<int>& prices){
        int n= prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0)); 
        vector<vector<int>> next(2, vector<int>(3, 0)); 

        for(int index=n-1; index>=0; index--){
            for(int buyOrSell=0; buyOrSell<=1; buyOrSell++){
                for(int maxSell=1; maxSell>=0; maxSell--){
                    int profit= 0;
                    // Buy Allowed
                    if(buyOrSell){
                        int buy= -prices[index]+next[0][maxSell];
                        int skip= next[1][maxSell];
                        profit= max(buy, skip);
                    }
                    else{
                        int sell= prices[index]+next[1][maxSell+1];
                        int skip= next[0][maxSell];
                        profit= max(sell, skip);
                    }
                    curr[buyOrSell][maxSell]= profit;
                }
                next= curr;
            }
        }
        
        return curr[1][0];
    }

    int maxProfit(vector<int>& prices) {
        // Simple Recursive Solution
        // return solve(0, 1, prices, 0);

        // Recursion + Memoization (Top-Down Approach)
        // int n= prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, prices, 0, dp);

        return solve(prices);

    }
};