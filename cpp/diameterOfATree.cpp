class Solution {
    int diameter(TreeNode* root,int& height){
        if(root == NULL){
            height=0;
            return 0;
        }
        int lh=0,rh=0;
        int lDiameter = diameter(root->left,lh);
        int rDiameter = diameter(root->right,rh);
        int currDiameter = lh+rh;
        height = max(rh,lh)+1;
        return max(currDiameter,max(lDiameter,rDiameter));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        return diameter(root,height);
    }
};