
// https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    // Simple Recursive Solution
    // bool solve(string& s, string& p, int i, int j){
    //     if(i<0 && j<0)
    //         return true;
    //     if(i>=0 && j<0)
    //         return false;
    //     if(i<0 && j>=0){
    //         for(int k=0; k<=j; k++){
    //             if(p[k]!='*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     //match
    //     if(s[i]==p[j] || p[j]=='?'){
    //         return solve(s, p, i-1, j-1);
    //     }
    //     else if(p[j]=='*'){
    //         return (solve(s, p, i-1, j) || solve(s, p, i, j-1));
    //     }
    //     else
    //         return false;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
    //     if(i==0 && j==0)
    //         return true;
    //     if(i>0 && j==0)
    //         return false;
    //     if(i==0 && j>0){
    //         for(int k=1; k<=j; k++){
    //             if(p[k-1]!='*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     if(dp[i][j]!=-1)
    //         return dp[i][j];

    //     //match
    //     bool ans;
    //     if(s[i-1]==p[j-1] || p[j-1]=='?'){
    //         ans= solve(s, p, i-1, j-1, dp);
    //     }
    //     else if(p[j-1]=='*'){
    //         ans= (solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp));
    //     }
    //     else
    //         ans= false;

    //     dp[i][j]= ans;

    //     return dp[i][j];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // bool solve(string& s, string& p){

    //     vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, 0));
    //     dp[0][0]= true;

    //     for(int j=1; j<=p.length(); j++){
    //         bool flag= true;
    //         for(int k=1; k<=j; k++){
    //             if(p[k-1]!='*'){
    //                 flag= false;
    //                 break;
    //             }
    //         }
    //         dp[0][j]= flag;
    //     }

    //     for(int i=1; i<=s.length(); i++){
    //         for(int j=1; j<=p.length(); j++){ 
    //             //match
    //             bool ans;
    //             if(s[i-1]==p[j-1] || p[j-1]=='?'){
    //                 ans= dp[i-1][j-1];
    //             }
    //             else if(p[j-1]=='*'){
    //                 ans= (dp[i-1][j] || dp[i][j-1]);
    //             }
    //             else
    //                 ans= false;
    //             dp[i][j]= ans;
    //         }
    //     }

    //     return dp[s.length()][p.length()];
    // }

    bool solve(string& s, string& p){

        vector<int> prev(p.length()+1, 0);
        vector<int> curr(p.length()+1, 0);
        prev[0]= true;

        for(int j=1; j<=p.length(); j++){
            bool flag= true;
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*'){
                    flag= false;
                    break;
                }
            }
            prev[j]= flag;
        }

        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){ 
                //match
                bool ans;
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    ans= prev[j-1];
                }
                else if(p[j-1]=='*'){
                    ans= (prev[j] || curr[j-1]);
                }
                else
                    ans= false;
                curr[j]= ans;
            }
            prev= curr;
        }

        return prev[p.length()];
    }

    bool isMatch(string s, string p) {
        // Simple Recursive Solution
        // return solve(s, p, s.length()-1, p.length()-1);

        // vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        // return solve(s, p, s.length(), p.length(), dp);

        return solve(s, p);

    }
};