
// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(TreeNode* node, int& diameter) {
        if (node==NULL) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
    /*
    pair<int, int> getDiameterAndHeight(TreeNode* root){
        pair<int, int> ans= make_pair(0,0);
        if(root==NULL)
            return ans;

        pair<int, int> left= getDiameterAndHeight(root->left);
        pair<int, int> right= getDiameterAndHeight(root->right);

        int leftDiameter= left.first;
        int rightDiameter= right.first;
        int height= left.second + right.second + 1;

        ans.first= max(leftDiameter, max(rightDiameter, height));
        ans.second= max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root){
        return getDiameterAndHeight(root).first;
    }
    */

    /*
    int getHeight(TreeNode* &root){
        if(root==NULL)
            return 0;
        int left= getHeight(root->left);
        int right= getHeight(root->right);

        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left= diameterOfBinaryTree(root->left);
        int right= diameterOfBinaryTree(root->right);
        int depth= getHeight(root->left) + getHeight(root->right) + 1;
        return max(left, max(right, depth));
    }
    */
};











