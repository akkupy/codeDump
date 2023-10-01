
// https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(string& s1, string& s2, int i, int j){
    //     if(i==s1.length())
    //         return s2.length()-j;
    //     if(j==s2.length())
    //         return s1.length()-i;

    //     int ans=0;
    //     if(s1[i]==s2[j]){
    //         ans= solve(s1, s2, i+1, j+1);
    //     }
    //     else{
    //         int insertAns= 1 + solve(s1, s2, i, j+1);
    //         int deleteAns= 1 + solve(s1, s2, i+1, j);
    //         int replaceAns= 1 + solve(s1, s2, i+1, j+1);
    //         ans= min(insertAns, min(deleteAns, replaceAns));
    //     }
    //     return ans;        
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    //     if(i==s1.length())
    //         return s2.length()-j;
    //     if(j==s2.length())
    //         return s1.length()-i;

    //     if(dp[i][j]!=-1)
    //         return dp[i][j];

    //     int ans=0;
    //     if(s1[i]==s2[j]){
    //         ans= solve(s1, s2, i+1, j+1, dp);
    //     }
    //     else{
    //         int insertAns= 1 + solve(s1, s2, i, j+1, dp);
    //         int deleteAns= 1 + solve(s1, s2, i+1, j, dp);
    //         int replaceAns= 1 + solve(s1, s2, i+1, j+1, dp);
    //         ans= min(insertAns, min(deleteAns, replaceAns));
    //     }

    //     dp[i][j]= ans;

    //     return dp[i][j];        
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(string& s1, string& s2){

    //     vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    //     for(int i=0; i<s2.length(); i++){
    //         dp[s1.length()][i]= s2.length()-i;
    //     }
    //     for(int i=0; i<s1.length(); i++){
    //         dp[i][s2.length()]= s1.length()-i;
    //     }

    //     for(int i= s1.length()-1; i>=0; i--){
    //         for(int j= s2.length()-1; j>=0; j--){
    //             int ans=0;
    //             if(s1[i]==s2[j]){
    //                 ans= dp[i+1][j+1];
    //             }
    //             else{
    //                 int insertAns= 1 + dp[i][j+1];
    //                 int deleteAns= 1 + dp[i+1][j];
    //                 int replaceAns= 1 + dp[i+1][j+1];
    //                 ans= min(insertAns, min(deleteAns, replaceAns));
    //             }
    //             dp[i][j]= ans;
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solve(string& s1, string& s2){

        vector<int> curr(s2.length()+1, 0);
        vector<int> next(s2.length()+1, 0);
        
        for(int i=0; i<s2.length(); i++){
            next[i]= s2.length()-i;
        }

        for(int i= s1.length()-1; i>=0; i--){
            for(int j= s2.length()-1; j>=0; j--){
                curr[s2.length()]= s1.length()-i;
                int ans=0;
                if(s1[i]==s2[j]){
                    ans= next[j+1];
                }
                else{
                    int insertAns= 1 + curr[j+1];
                    int deleteAns= 1 + next[j];
                    int replaceAns= 1 + next[j+1];
                    ans= min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j]= ans;
            }
            next= curr;
        }
        return curr[0];
    }


    int minDistance(string word1, string word2) {
        // Simple Recursive Solution
        // return solve(word1, word2, 0, 0);

        // Recursion + Memoization (Top-Down Approach)
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solve(word1, word2, 0, 0, dp);

        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        return solve(word1, word2);

    }
};









