
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &values){
        if(root==NULL)
            return;

        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        
        /* Using recursion
        inorder(root, values);
        */

        //Morris Traversal
        /*
        1. Initialize current as root 
        2. While current is not NULL
        If the current does not have left child
            a) Print current’s data
            b) Go to the right, i.e., current = current->right
        Else
            a) Find rightmost node in current left subtree OR
                    node whose right child == current.
                If we found right child == current
                    a) Update the right child as NULL of that node whose right child is current
                    b) Print current’s data
                    c) Go to the right, i.e. current = current->right
                Else
                    a) Make current as the right child of that rightmost 
                        node we found; and 
                    b) Go to this left child, i.e., current = current->left
        */
        TreeNode* curr= root;
        TreeNode* pre= NULL;

        while(curr!=NULL){
            
            if(curr->left==NULL){
                values.push_back(curr->val);
                curr=curr->right;
            }
            else{
                pre= curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                    pre= pre->right;

                if(pre->right==NULL){
                    pre->right= curr;
                    curr= curr->left;
                }
                else{
                    pre->right=NULL;
                    values.push_back(curr->val);
                    curr= curr-> right;
                }
            }
        }
        return values;
    }
};












