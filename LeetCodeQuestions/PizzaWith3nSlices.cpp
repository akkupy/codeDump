
// https://leetcode.com/problems/pizza-with-3n-slices/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int>& slices, int index, int endIndex, int n){
    //     if(n==0 || index>endIndex){
    //         return 0;
    //     }

    //     int include= slices[index] + solve(slices, index+2, endIndex, n-1);
    //     int exclude= 0 + solve(slices, index+1, endIndex, n);

    //     return max(include, exclude);
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int>& slices, int index, int endIndex, int n, vector<vector<int>>& dp){
    //     if(n==0 || index>endIndex){
    //         return 0;
    //     }

    //     if(dp[index][n]!=-1)
    //         return dp[index][n];

    //     int include= slices[index] + solve(slices, index+2, endIndex, n-1, dp);
    //     int exclude= 0 + solve(slices, index+1, endIndex, n, dp);

    //     dp[index][n]= max(include, exclude);

    //     return dp[index][n];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(vector<int>& slices){
    //     int n= slices.size();
    //     vector<vector<int>> dp1(n+2, vector<int>(n+2, 0));

    //     for(int index= n-2; index>=0; index--){
    //         for(int k=1; k<=n/3; k++){
    //             int include= slices[index] + dp1[index+2][k-1];
    //             int exclude= 0 + dp1[index+1][k];

    //             dp1[index][k]= max(include, exclude);
    //         }
    //     }

    //     vector<vector<int>> dp2(n+2, vector<int>(n+2, 0));

    //     for(int index= n-1; index>=1; index--){
    //         for(int k=1; k<=n/3; k++){
    //             int include= slices[index] + dp2[index+2][k-1];
    //             int exclude= 0 + dp2[index+1][k];

    //             dp2[index][k]= max(include, exclude);
    //         }
    //     }

    //     return max(dp1[0][n/3], dp2[1][n/3]);

    // }

    
    int solve(vector<int>& slices){
        int n= slices.size();
        vector<int> curr1(n+2, 0);
        vector<int> next1(n+2, 0);
        vector<int> nextForward1(n+2, 0);

        for(int index= n-2; index>=0; index--){
            for(int k=1; k<=n/3; k++){
                int include= slices[index] + nextForward1[k-1];
                int exclude= 0 + next1[k];

                curr1[k]= max(include, exclude);
            }
            nextForward1= next1;
            next1= curr1;
        }

        vector<int> curr2(n+2, 0);
        vector<int> next2(n+2, 0);
        vector<int> nextForward2(n+2, 0);

        for(int index= n-1; index>=1; index--){
            for(int k=1; k<=n/3; k++){
                int include= slices[index] + nextForward2[k-1];
                int exclude= 0 + next2[k];

                curr2[k]= max(include, exclude);
            }
            nextForward2= next2;
            next2= curr2;
        }

        return max(next1[n/3], next2[n/3]);

    }

    int maxSizeSlices(vector<int>& slices) {
        // Simple Recursive Solution
        // int n= slices.size();
        // int include= solve(slices, 0, n-2, n/3);
        // int exclude= solve(slices, 1, n-1, n/3);

        // return max(include, exclude);

        // int n= slices.size();
        // vector<vector<int>> dp1(n+1, vector<int>(n+1, -1));
        // vector<vector<int>> dp2(n+1, vector<int>(n+1, -1));
        // int include= solve(slices, 0, n-2, n/3, dp1);
        // int exclude= solve(slices, 1, n-1, n/3, dp2);

        // return max(include, exclude);

        return solve(slices);

    }
};