class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long sum=arr[0];
        long currsum=arr[0];
        for(int i=1;i<n;i++)
        {
            currsum=Math.max(currsum+arr[i],arr[i]);
            sum=Math.max(sum,currsum);
        }
        return sum;
        
    }
    
}