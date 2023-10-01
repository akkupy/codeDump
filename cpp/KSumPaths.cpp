
// https://practice.geeksforgeeks.org/problems/k-sum-paths/1

class Solution{
  public:
    void checkPathSum(Node* root, int k, int &count, vector<int> paths){
        if(root==NULL)
            return;
        
        paths.push_back(root->data);
        
        checkPathSum(root->left, k, count, paths);
        checkPathSum(root->right, k, count, paths);
        
        int sum= 0;
        for(int i=paths.size()-1; i>=0; i--){
            sum+= paths[i];
            if(sum==k)
                count++;
        }
        
        
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> paths;
        int count= 0;
        checkPathSum(root, k, count, paths);
        
        return count;
        
    }
};

