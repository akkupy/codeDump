
// https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int> &nums, int target){
    //     if(target==0){
    //         return 1;
    //     }
    //     else if(target<0)
    //         return 0;

    //     int ans= 0;
    //     for(auto i : nums){
    //         ans += solve(nums, target-i, dp);
    //     }

    //     return ans;
            
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int> &nums, int target, vector<int> &dp){
    //     if(target==0){
    //         return 1;
    //     }
    //     else if(target<0)
    //         return 0;

    //     if(dp[target]!=-1)
    //         return dp[target];

    //     int ans= 0;
    //     for(auto i : nums){
    //         ans += solve(nums, target-i, dp);
    //     }
    //     dp[target]= ans;
    //     return dp[target];
            
    // }

    int solve(vector<int> &nums, int target){
        vector<int> dp(target+1, 0);
        dp[0]= 1;

        for(int i=0; i<=target; i++){
            for(auto j : nums){
                if(i-j>=0){
                    dp[i] += dp[i-j]*1l;
                }
            }
        }

        return dp[target];
            
    }

    int combinationSum4(vector<int>& nums, int target) {

        // Simple Recursive Solution
        // return solve(nums, target);


        // Recursion + Memoization (Top-Down Approach)
        // vector<int> dp(target+1, -1);
        // return solve(nums, target, dp);

        return solve(nums, target);

    }
};