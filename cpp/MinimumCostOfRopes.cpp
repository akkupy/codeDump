
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(long long i=0; i<n; i++){
            minHeap.push(arr[i]);
        }
        long long ans= 0;
        while(minHeap.size()>1){
            long long firstMinimum= minHeap.top();
            minHeap.pop();
            long long secondMinimum= minHeap.top();
            minHeap.pop();
            long long sum= firstMinimum + secondMinimum;
            ans+=sum;
            minHeap.push(sum);
        }
        return ans;
    }
};
