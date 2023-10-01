
// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(string text1, string text2, int i, int j){
    //     if(i==text1.length())
    //         return 0;
    //     if(j==text2.length())
    //         return 0;

    //     int ans= 0;
    //     if(text1[i]==text2[j]){
    //         ans= 1 + solve(text1, text2, i+1, j+1);
    //     }
    //     else{
    //         ans= max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    //     }
    //     return ans;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
    //     if(i==text1.length())
    //         return 0;
    //     if(j==text2.length())
    //         return 0;

    //     if(dp[i][j]!=-1)
    //         return dp[i][j];

    //     int ans= 0;
    //     if(text1[i]==text2[j]){
    //         ans= 1 + solve(text1, text2, i+1, j+1, dp);
    //     }
    //     else{
    //         ans= max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
    //     }

    //     dp[i][j]= ans;

    //     return dp[i][j];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(string& text1, string& text2){
    //     vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));

    //     for(int i= text1.length()-1; i>=0; i--){
    //         for(int j= text2.length()-1; j>=0; j--){
    //             int ans= 0;
    //             if(text1[i]==text2[j]){
    //                 ans= 1 + dp[i+1][j+1];
    //             }
    //             else{
    //                 ans= max(dp[i+1][j], dp[i][j+1]);
    //             }
    //             dp[i][j]= ans;
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solve(string& text1, string& text2){

        vector<int> curr(text2.length()+1, 0);
        vector<int> next(text2.length()+1, 0);

        for(int i= text1.length()-1; i>=0; i--){
            for(int j= text2.length()-1; j>=0; j--){
                int ans= 0;
                if(text1[i]==text2[j]){
                    ans= 1 + next[j+1];
                }
                else{
                    ans= max(next[j], curr[j+1]);
                }
                curr[j]= ans;
            }
            next= curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Simple Recursive Solution
        // return solve(text1, text2, 0, 0);

        // Recursion + Memoization
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solve(text1, text2, 0, 0, dp);

        return solve(text1, text2);

    }
};