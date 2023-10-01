
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
    //     if(index==nums1.size())
    //         return 0;

    //     int prev1= nums1[index-1];
    //     int prev2= nums2[index-1];

    //     if(swapped)
    //         swap(prev1, prev2);
        
    //     int ans= INT_MAX;
    //     // No Swap
    //     if(nums1[index]>prev1 && nums2[index]>prev2)
    //         ans= solve(nums1, nums2, index+1, false);
        
    //     // Swapped
    //     if(nums1[index]>prev2 && nums2[index]>prev1)
    //         ans= min(ans, 1+solve(nums1, nums2, index+1, true));

    //     return ans;

    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp) {
    //     if(index==nums1.size())
    //         return 0;

    //     if(dp[index][swapped]!=-1)
    //         return dp[index][swapped];

    //     int prev1= nums1[index-1];
    //     int prev2= nums2[index-1];

    //     if(swapped)
    //         swap(prev1, prev2);
        
    //     int ans= INT_MAX;
    //     // No Swap
    //     if(nums1[index]>prev1 && nums2[index]>prev2)
    //         ans= solve(nums1, nums2, index+1, false, dp);
        
    //     // Swapped
    //     if(nums1[index]>prev2 && nums2[index]>prev1)
    //         ans= min(ans, 1+solve(nums1, nums2, index+1, true, dp));

    //     dp[index][swapped]= ans;

    //     return dp[index][swapped];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(vector<int>& nums1, vector<int>& nums2) {
    //     vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));

    //     for(int index= nums1.size()-1; index>=1; index--){
    //         for(int swapped=1; swapped>=0; swapped--){
    //             int prev1= nums1[index-1];
    //             int prev2= nums2[index-1];

    //             if(swapped)
    //                 swap(prev1, prev2);
                
    //             int ans= INT_MAX;
    //             // No Swap
    //             if(nums1[index]>prev1 && nums2[index]>prev2)
    //                 ans= dp[index+1][0];
                
    //             // Swapped
    //             if(nums1[index]>prev2 && nums2[index]>prev1)
    //                 ans= min(ans, 1+dp[index+1][1]);

    //             dp[index][swapped]= ans;
    //         }
    //     }
    //     return dp[1][0];
    // }

    int solve(vector<int>& nums1, vector<int>& nums2) {
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index= nums1.size()-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int prev1= nums1[index-1];
                int prev2= nums2[index-1];

                if(swapped)
                    swap(prev1, prev2);
                
                int ans= INT_MAX;
                // No Swap
                if(nums1[index]>prev1 && nums2[index]>prev2)
                    ans= next[0];
                
                // Swapped
                if(nums1[index]>prev2 && nums2[index]>prev1)
                    ans= min(ans, 1+next[1]);

                curr[swapped]= ans;
            }
            next= curr;
        }
        return next[0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        // bool swapped = false;
        // Simple Recursive Solution
        // return solve(nums1, nums2, 1, swapped);

        // Recursion + Memoization (Top-Down Approach)
        // int n= nums1.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(nums1, nums2, 1, swapped, dp);

        return solve(nums1, nums2);
    }
};