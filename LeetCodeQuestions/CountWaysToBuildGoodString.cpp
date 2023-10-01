
// https://leetcode.com/problems/count-ways-to-build-good-strings/description/

class Solution {
public:
    int solve(int len, int low, int high, int zero, int one){
        if(len>high)
            return 0;
        
        int ans= 0;
        ans= solve(len+zero, low, high, zero, one)%1000000007;
        ans= (ans + solve(len+one, low, high, zero, one)%1000000007)%1000000007;

        return ans;
    }

    int solveMem(int len, int low, int high, int zero, int one, vector<int> &dp){
        if(len>high)
            return 0;
        
        if(dp[len]!=-1)
            return dp[len];

        int ans= 0;
        if(len>=low && len<=high)
            ans++;
        ans+= solveMem(len+zero, low, high, zero, one, dp)%1000000007;
        ans= (ans%1000000007 + solveMem(len+one, low, high, zero, one, dp)%1000000007)%1000000007;
        dp[len]= ans;

        return dp[len];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // return solve(0, low, high, zero, one)%1000000007;

        vector<int> dp(high+1, -1);
        return solveMem(0, low, high, zero, one, dp);

    }
};