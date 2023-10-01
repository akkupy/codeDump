
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution{
    struct Node
    {
        int data;
        int i;
        int j;
        Node(int data,int i,int j)
        {
            this->data=data;
            this->i=i;
            this->j=j;
        }
    };
    
    class compare
    {
        public:
        bool operator()(Node* a,Node* b)
        {
            return a->data>b->data;
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        for(int i=0;i<K;i++)
        {
            Node* temp=new Node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        while(!minHeap.empty())
        {
            Node* temp=minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();
            int i=temp->i;
            int j=temp->j;
            if(j+1<arr[i].size())
            {
                Node* temp1=new Node(arr[i][j+1],i,j+1);
                minHeap.push(temp1);
            }
        }
        return ans;
    }
}


/*
#include<queue>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto i : arr){
            for(int j=0; j<K; j++)
                minHeap.push(i[j]);
        }
        
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};
*/