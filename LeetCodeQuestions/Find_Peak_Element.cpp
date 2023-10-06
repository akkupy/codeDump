// Time complexity:
// O(logn)

// Space complexity:
// O(1)

//100% beats time and 95% beats space requirements!----->>>>>Simplest Brute force approach!!!!!

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int index=0;
        for(int i=1;i<arr.size()-1;i++){
           if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
               index=i;
               break;
           }
       }
       if(index==0 && arr.size()>=2){
           if(arr[0]>arr[1]){
               index=0;
           }
           else if(arr[arr.size()-1]>arr[arr.size()-2]){
               index=arr.size()-1;
           }
       }
       return index;
    }
};
