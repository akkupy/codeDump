
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int solve(vector<int>& prices, int fees){

        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int index= n-1; index>=0; index--){
            for(int buyOrSell= 0; buyOrSell<=1; buyOrSell++){
                int profit= 0;
                if(buyOrSell){
                    int buy= -prices[index] + dp[index+1][0];
                    int skip= dp[index+1][1];
                    profit= max(buy, skip);
                }
                else{
                    int sell= prices[index] + dp[index+1][1] - fees;
                    int skip= dp[index+1][0];
                    profit= max(sell, skip);
                }
                dp[index][buyOrSell]= profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};