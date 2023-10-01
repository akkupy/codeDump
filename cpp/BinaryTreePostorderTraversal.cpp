
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    void postorder(TreeNode* root, vector<int> &values){
        if(root==NULL)
            return;

        postorder(root->left, values);
        postorder(root->right, values);
        values.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;
        postorder(root, values);
        return values;
    }
};