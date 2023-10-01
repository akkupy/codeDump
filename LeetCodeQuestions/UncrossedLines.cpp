
// https://leetcode.com/problems/uncrossed-lines/

class Solution {
public:
    int findMatchIndex(int f, int startIndex, vector<int>& nums){
        for(int i=startIndex; i<nums.size(); i++){
            if(nums[i]==f)
                return i;
        }
        return -1;
    }

    int findMatchIndexReverse(int f, int startIndex, vector<int>& nums){
        for(int i=startIndex; i>=0; i--){
            if(nums[i]==f)
                return i;
        }
        return -1;
    }

    int solveRec(int n1, int n2, vector<int>& nums1, vector<int>& nums2){
        if(n1>=nums1.size() || n2>=nums2.size())
            return 0;
        
        int ans= 0;
        for(int i=n1; i<nums1.size(); i++){
            int findIndex= findMatchIndex(nums1[i], n2, nums2);
            if(findIndex!=-1){
                int include= 1 + solveRec(i+1, findIndex+1, nums1, nums2);
                int exclude= solveRec(i+1, n2, nums1, nums2);
                ans= max(ans, max(include, exclude));
            }
        }
        return ans;
    }

    int solveMem(int n1, int n2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(n1>=nums1.size() || n2>=nums2.size())
            return 0;
        
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];

        int ans= 0;
        for(int i=n1; i<nums1.size(); i++){
            int findIndex= findMatchIndex(nums1[i], n2, nums2);
            if(findIndex!=-1){
                int include= 1 + solveMem(i+1, findIndex+1, nums1, nums2, dp);
                int exclude= solveMem(i+1, n2, nums1, nums2, dp);
                ans= max(ans, max(include, exclude));
            }
        }
        dp[n1][n2]= ans;
        return ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));

        for(int i=0; i<=nums1.size(); i++){
            for(int j=0; j<=nums2.size(); j++){
                if(i==0 || j==0){
                    dp[i][j]= 0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Simple Recursive Solution
        // return solveRec(0, 0, nums1, nums2);

        // Recursion + Memoization(Top-Down Approach)
        // vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        // return solveMem(0, 0, nums1, nums2, dp);

        return solveTab(nums1, nums2);

    }
};















