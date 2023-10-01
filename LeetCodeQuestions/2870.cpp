//2870. Minimum Number of Operations to Make Array Empty

//using maps and basic math logic
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        int c=0;
       
        for(auto i:m)
        {
            int x=i.second;
            if(x==1)
            return -1;
            if(x%3==0)
            c+=x/3;
            else if(x%3==1)
            {
                c+=(x-4)/3+2;
            }
            else
            {c+=((x-2)/3)+1;}
        }
        return c;
    }
};