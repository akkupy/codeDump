//The approach used here is binary search!!!!!
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int last=-1;
        int first=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        for(int i=last;i>=0;i--){
            if(nums[i]!=target){
                first=i+1;
                break;
            }
            else if(i-1<0){
                first=0;
                break;
            }
        }
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};
