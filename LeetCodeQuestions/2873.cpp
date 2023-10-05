//2873. Maximum Value of an Ordered Triplet I

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i<j and j<k)
                    {
                        ans=max(ans,(nums[i]-nums[j])*(long long)nums[k]);
                    }
                }
            }
        }
        return ans;
    }
};