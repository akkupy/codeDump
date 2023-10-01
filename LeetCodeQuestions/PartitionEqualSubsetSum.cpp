
// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    // Simple Recursive Solution
    // bool solve(vector<int>& nums, int index, int target){
    //     if(index>=nums.size())
    //         return false;
    //     if(target==0)
    //         return true;
    //     if(target<0)
    //         return false;

    //     bool include= solve(nums, index+1, target-nums[index]);
    //     bool exclude= solve(nums, index+1, target);

    //     return include || exclude;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
    //     if(index>=nums.size())
    //         return false;
    //     if(target==0)
    //         return true;
    //     if(target<0)
    //         return false;

    //     if(dp[index][target]!=-1)
    //         return dp[index][target];

    //     bool include= solve(nums, index+1, target-nums[index], dp);
    //     bool exclude= solve(nums, index+1, target, dp);

    //     dp[index][target]= include||exclude;

    //     return dp[index][target];
    // }

    // Tabulation Approach (Bottom-Up Approach)
    // bool solve(vector<int>& nums, int target){
    //     vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, 0));
    //     for(int i=0; i<=nums.size(); i++)
    //         dp[i][0]= 1;

    //     for(int index=nums.size()-1; index>=0; index--){
    //         for(int t=0; t<=target; t++){    
    //             bool include= false;
    //             if(t-nums[index]>=0)
    //                 include= dp[index+1][t-nums[index]];
    //             bool exclude= dp[index+1][t];

    //             dp[index][t]= include||exclude;
    //         }
    //     }

    //     return dp[0][target];
    // }

    bool solve(vector<int>& nums, int target){
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        next[0]= 1;

        for(int index=nums.size()-1; index>=0; index--){
            for(int t=0; t<=target; t++){    
                bool include= false;
                if(t-nums[index]>=0)
                    include= next[t-nums[index]];
                bool exclude= next[t];

                curr[t]= include||exclude;
            }
            next= curr;
        }

        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int total= 0;
        for(auto i : nums)
            total+= i;
        
        if(total%2!=0)
            return false;
        
        // Simple Recursive Solution
        // return solve(nums, 0, total/2);

        // vector<vector<int>> dp(nums.size()+1, vector<int>((total/2)+1, -1));
        // return solve(nums, 0, total/2, dp);
        
        return solve(nums, total/2);
    }
};