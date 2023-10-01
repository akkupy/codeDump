
// https://leetcode.com/problems/reducing-dishes/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int>& satisfaction, int index, int time){
    //     if(index==satisfaction.size())
    //         return 0;
        
    //     int include= satisfaction[index]*(time+1) + solve(satisfaction, index+1, time+1);
    //     int exclude= 0 + solve(satisfaction, index+1, time);

    //     return max(include, exclude);

    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp){
    //     if(index==satisfaction.size())
    //         return 0;

    //     if(dp[index][time]!=-1)
    //         return dp[index][time];
        
    //     int include= satisfaction[index]*(time+1) + solve(satisfaction, index+1, time+1, dp);
    //     int exclude= 0 + solve(satisfaction, index+1, time, dp);

    //     dp[index][time]= max(include, exclude);

    //     return dp[index][time];

    // }

    // Tabulation (Bottom-Up Approach)
    // int solve(vector<int>& satisfaction){
    //     int n= satisfaction.size();
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
    //     for(int index= n-1; index>=0; index--){
    //         for(int time= index; time>=0; time--){
    //             int include= satisfaction[index]*(time+1) + dp[index+1][time+1];
    //             int exclude= 0 + dp[index+1][time];

    //             dp[index][time]= max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solve(vector<int>& satisfaction){
        int n= satisfaction.size();
        
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int index= n-1; index>=0; index--){
            for(int time= index; time>=0; time--){
                int include= satisfaction[index]*(time+1) + next[time+1];
                int exclude= 0 + next[time];

                curr[time]= max(include, exclude);
            }
            next= curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // Simple Recursive Solution
        // return solve(satisfaction, 0, 0);

        // Recursion + Memoization
        // int n= satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        // return solve(satisfaction, 0, 0, dp);

        return solve(satisfaction);

    }
};