
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int> &values, int i, int j){
    //     if(i+1==j)
    //         return 0;

    //     int ans= INT_MAX;
    //     for(int k=i+1; k<j; k++){
    //         ans= min(ans, values[i]*values[j]*values[k] + solve(values, i, k) + solve(values, k, j));
    //     }
    //     return ans;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int> &values, int i, int j, vector<vector<int>> &dp){
    //     if(i+1==j)
    //         return 0;

    //     if(dp[i][j]!=-1)
    //         return dp[i][j];

    //     int ans= INT_MAX;
    //     for(int k=i+1; k<j; k++){
    //         ans= min(ans, values[i]*values[j]*values[k] + solve(values, i, k, dp) + solve(values, k, j, dp));
    //     }

    //     dp[i][j]= ans;

    //     return dp[i][j];
    // }

    int solve(vector<int> &values){
        int n= values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i= n-1; i>=0; i--){
            for(int j= i+2; j<n; j++){
                int ans= INT_MAX;
                for(int k=i+1; k<j; k++){
                    ans= min(ans,values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j]= ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        // Simple Recursive Solution
        // return solve(values, 0, values.size()-1);

        // Recursion + Memoization (Top-Down Approach)
        // int n= values.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(values, 0, n-1, dp);

        return solve(values);
    }
};