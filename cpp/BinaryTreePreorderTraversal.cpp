
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void preorder(TreeNode* root, vector<int> &values){
        if(root==NULL)
            return;

        values.push_back(root->val);
        preorder(root->left, values);
        preorder(root->right, values);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        preorder(root, values);
        return values;
    }
};