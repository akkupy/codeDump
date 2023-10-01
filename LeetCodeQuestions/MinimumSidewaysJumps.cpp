
// https://leetcode.com/problems/minimum-sideway-jumps/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int>& obstacles, int currLane, int currPos){
    //     int n= obstacles.size()-1;
    //     if(currPos==n)
    //         return 0;
        
    //     if(obstacles[currPos+1]!=currLane){
    //         return solve(obstacles, currLane, currPos+1);
    //     }
    //     else{
    //         int ans= INT_MAX;
    //         for(int i=1; i<=3; i++){
    //             if(currLane!=i && obstacles[currPos]!=i){
    //                 ans= min(ans, 1 + solve(obstacles, i, currPos));
    //             }
    //         }
    //         return ans;
    //     }

    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>> &dp){
    //     int n= obstacles.size()-1;
    //     if(currPos==n)
    //         return 0;

    //     if(dp[currLane][currPos]!=-1)
    //         return dp[currLane][currPos];
        
    //     if(obstacles[currPos+1]!=currLane){
    //         return solve(obstacles, currLane, currPos+1, dp);
    //     }
    //     else{
    //         int ans= INT_MAX;
    //         for(int i=1; i<=3; i++){
    //             if(currLane!=i && obstacles[currPos]!=i){
    //                 ans= min(ans, 1 + solve(obstacles, i, currPos, dp));
    //             }
    //         }
    //         dp[currLane][currPos]= ans;
    //         return dp[currLane][currPos];
    //     }

    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(vector<int> &obstacles){
    //     int n = obstacles.size()-1;
    //     vector<vector<int>> dp(4, vector<int>(n+1, 1e9));
    //     dp[0][n]= 0;
    //     dp[1][n]= 0;
    //     dp[2][n]= 0;
    //     dp[3][n]= 0;

    //     for(int currPos= n-1; currPos>=0; currPos--){
    //         for(int currLane= 1; currLane<=3; currLane++){
    //             if(obstacles[currPos+1]!=currLane){
    //                 dp[currLane][currPos]= dp[currLane][currPos+1];
    //             }
    //             else{
    //                 int ans= 1e9;
    //                 for(int i=1; i<=3; i++){
    //                     if(currLane!=i && obstacles[currPos]!=i){
    //                         ans= min(ans, 1 + dp[i][currPos+1]);
    //                     }
    //                 }
    //                 dp[currLane][currPos]= ans;
    //             }
    //         }
    //     }

    //     return min(dp[1][0]+1, min(dp[2][0], dp[3][0]+1));

    // }

    int solve(vector<int> &obstacles){
        int n = obstacles.size()-1;
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);
        next[0]= 0;
        next[1]= 0;
        next[2]= 0;
        next[3]= 0;

        for(int currPos= n-1; currPos>=0; currPos--){
            for(int currLane= 1; currLane<=3; currLane++){
                if(obstacles[currPos+1]!=currLane){
                    curr[currLane]= next[currLane];
                }
                else{
                    int ans= 1e9;
                    for(int i=1; i<=3; i++){
                        if(currLane!=i && obstacles[currPos]!=i){
                            ans= min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane]= ans;
                }
            }
            next= curr;
        }

        return min(next[1]+1, min(next[2], next[3]+1));

    }

    int minSideJumps(vector<int>& obstacles) {
        // Simple Recursive Solution
        // return solve(obstacles, 2, 0);

        // Recursion + Memoization (Top-Down Approach)
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solve(obstacles, 2, 0, dp);

        return solve(obstacles);

    }
};