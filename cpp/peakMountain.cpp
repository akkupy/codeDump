
//https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lb=0,ub=arr.size()-1,mid=lb+(ub-lb)/2;
        while(lb<ub){
            if(arr[mid]<arr[mid+1]){
                lb=mid+1;
            }else{
                ub=mid;
            }
            mid=lb+(ub-lb)/2;
        }
        return mid;
    }
};