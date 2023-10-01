
// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        pair<int,int> ans= make_pair(0,0);
        if(root==NULL)
            return ans;
            
        pair<int,int> leftAns= solve(root->left);
        pair<int,int> rightAns= solve(root->right);
        
        ans.first= root->data + leftAns.second + rightAns.second;
        ans.second= max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return ans;
        
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans= solve(root);
        return max(ans.first, ans.second);
        
    }
};


