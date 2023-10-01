
// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

class Solution{
    public:
    void heapify(vector<int> &arr, int i, int size){
        int largest= i;
        int left= 2*i+1;
        int right= 2*i+2;
        
        if(left<size && arr[largest]<arr[left])
            largest= left;
        if(right<size && arr[largest]<arr[right])
            largest= right;
        
        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, largest, size);
        }
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merged;
        merged.insert(merged.end(), a.begin(), a.end());
        merged.insert(merged.end(), b.begin(), b.end());
        for(int i= (n+m)/2-1; i>=0; i--){
            heapify(merged, i, n+m);
        }
        return merged;
    }
};