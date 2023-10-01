//2871. Split Array Into Maximum Number of Subarrays

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int a=nums[0];
        int n=nums.size();
        int c=0;
        int flag=0;
        if(n==1)
        return 1;
        for(int i=1;i<n;i++)
        {
            if(a==0)
            { flag=1;
                c++;
                a=nums[i];
            }
            else
            a=a&nums[i];
        }
        if(!flag)
        return 1;
        else
        if(a==0)
        return c+1;
        return c;
    }
};