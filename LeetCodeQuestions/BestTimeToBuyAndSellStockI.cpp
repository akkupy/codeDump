
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= prices[0];
        int profit= 0;
        for(auto i : prices){
            int diff= i-mini;
            profit= max(profit, diff);
            mini= min(mini, i);
        }
        return profit;
    }
};