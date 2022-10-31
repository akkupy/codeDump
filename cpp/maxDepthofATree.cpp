class Solution {
    void maxdepth(TreeNode* root,int &ans, int currHeight){
        if(root==NULL)
            return ;
        ans = max(ans,currHeight);
        if(root->left)
            maxdepth(root->left,ans,currHeight+1);
        if(root->right)
            maxdepth(root->right,ans,currHeight+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};