class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = 0; i < n-1; i++) {
          if(nums[i]<nums[i+1]) idx = i;
        }
        if(idx == -1) {
          reverse(nums.begin(), nums.end());
          return;
        }
        int l = idx + 1;
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) l = i;
        }
        swap(nums[idx], nums[l]);
        reverse(nums.begin() + 1 + idx, nums.end());
        return;
    }
};
