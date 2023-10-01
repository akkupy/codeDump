
// https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info{
    public:
        int max;
        int min;
        bool isBST;
        int size;
};
info solve(TreeNode<int>* root, int &ans){
    if(root==NULL)
        return {INT_MIN, INT_MAX, true, 0};
    
    info left= solve(root->left, ans);
    info right= solve(root->right, ans);
    
    info currNode;
    currNode.size= left.size+right.size+1;
    currNode.max= max(root->data, right.max);
    currNode.min= min(root->data, left.min);
    
    if(left.isBST && right.isBST && (root->data>left.max && root->data<right.min))
        currNode.isBST= true;
    else
        currNode.isBST= false;
    
    if(currNode.isBST)
        ans= max(ans, currNode.size);
    
    return currNode;
    
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize= 0;
    solve(root, maxSize);
    return maxSize;
}






