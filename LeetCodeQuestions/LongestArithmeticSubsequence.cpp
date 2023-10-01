
// https://leetcode.com/problems/longest-arithmetic-subsequence/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int>& nums, int i, int diff){
    //     if(i<=0)
    //         return 0;

    //     int ans= 0;
    //     for(int j=i-1; j>=0; j--){
    //         if(nums[i]-nums[j] == diff){
    //             ans= max(ans, 1 + solve(nums, j, diff));
    //         }
    //     }
    //     return ans;
    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int>& nums, int i, int diff, unordered_map<int,int> dp[]){
    //     if(i<=0)
    //         return 0;

    //     if(dp[i].count(diff))
    //         return dp[i][diff];

    //     int ans= 0;
    //     for(int j=i-1; j>=0; j--){
    //         if(nums[i]-nums[j] == diff){
    //             ans= max(ans, 1 + solve(nums, j, diff, dp));
    //         }
    //     }

    //     dp[i][diff]= ans;

    //     return dp[i][diff];
    // }

    int solve(vector<int>& nums){

        unordered_map<int,int> dp[nums.size()+1];

        int ans= 0;
        for(int i= 1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                int diff= nums[i]-nums[j];
                int count= 1;

                if(dp[j].count(diff))
                    count= dp[j][diff];

                dp[i][diff]= 1+count;
                ans= max(ans, dp[i][diff]);

            }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();

        // unordered_map<int,int> dp[nums.size()];

        // int ans= 0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j= i+1; j<nums.size(); j++){
        //         // Simple Recursive Solution
        //         // ans= max(ans, 2 + solve(nums, i, nums[j]-nums[i]));
        //         ans= max(ans, 2 + solve(nums, i, nums[j]-nums[i], dp));
        //     }
        // }
        // return ans;

        return solve(nums);

    }
};