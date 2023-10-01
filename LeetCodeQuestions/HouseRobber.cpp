
// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prevOne= nums[0];
        int prevTwo= 0;
        
        for(int i=1; i<nums.size(); i++){
            int include= prevTwo + nums[i];
            int exclude= prevOne;
            int ans= max(include, exclude);
            prevTwo= prevOne;
            prevOne= ans;
        }
        return prevOne;
    }
};