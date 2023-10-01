
// This is the solution for Jump Game question from Leetcode
// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l= nums.size()-1;
        for(int i=l; i>=0; i--){
            if(i + nums[i]>=l){
                l=i;
            }
        }
        return l==0;
    }
};