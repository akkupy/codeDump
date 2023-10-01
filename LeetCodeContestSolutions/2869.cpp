//2869. Minimum Operations to Collect Elements
//Using bit mask

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        long long n=(1ll<<k)-1;
        long long x=0;
    int c=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<=k)
            {
               // s.insert(nums[i]);
               x=x|(1ll<<(nums[i])-1);
               if(x==n)
               return nums.size()-i;
               
            }
           
            
        }
        return 0;
    }
};