// https://leetcode.com/problems/house-robber-iii/description/

class Solution {
public:
    map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        return rec(root);
    }

    int rec(TreeNode* root){
        if(!root) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int val = 0;
        if(root->left){
            val += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            val += rob(root->right->left)+rob(root->right->right);
        }
        return dp[root] = max(val+root->val,rob(root->left)+rob(root->right));
    }
};