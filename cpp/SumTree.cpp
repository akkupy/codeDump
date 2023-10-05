
// https://practice.geeksforgeeks.org/problems/sum-tree/1

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root){
        pair<bool,int> ans= make_pair(true, 0);
        if(root==NULL)
            return ans;
            
        if(root->left==NULL && root->right==NULL){
            ans.second= root->data;
            return ans;
        }
        
        pair<bool,int> left= isSumTreeFast(root->left);
        pair<bool,int> right= isSumTreeFast(root->right);
        
        bool leftAns= left.first;
        bool rightAns= right.first;
        
        bool rootCondition= (root->data == (left.second + right.second));
        
        if(leftAns && rightAns && rootCondition){
            ans.first= true;
            ans.second= 2*root->data;
        }else{
            ans.first= false;
        }
        
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeFast(root).first;
    }
};