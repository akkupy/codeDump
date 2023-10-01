
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    // Nearly Similar to Buy and Sell Stock IV Solution
    int solve(vector<int>& prices, int k){
        int n= prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0)); 
        vector<vector<int>> next(2, vector<int>(k+1, 0)); 

        for(int index=n-1; index>=0; index--){
            for(int buyOrSell=0; buyOrSell<=1; buyOrSell++){
                for(int maxSell=k-1; maxSell>=0; maxSell--){
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
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, k);
    }
};