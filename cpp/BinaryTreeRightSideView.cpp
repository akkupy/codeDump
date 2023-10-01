
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    void storeRightNodesValues(TreeNode* root, int level, vector<int> &ans){
        if(root==NULL)
            return;

        if(level == ans.size())
            ans.push_back(root->val);

        storeRightNodesValues(root->right, level+1, ans);
        storeRightNodesValues(root->left, level+1, ans);

    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        storeRightNodesValues(root, 0, ans);
        return ans;

        /*
        vector<int> ans;
        if(root==NULL)
            return ans;
        map<int,int> levelMapping;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<TreeNode*,int> front= q.front();
            q.pop();
            TreeNode* currNode= front.first;
            int level= front.second;
            
            levelMapping[level]= currNode->val;
            
            if(currNode->left)
                q.push(make_pair(currNode->left, level+1));
            if(currNode->right)
                q.push(make_pair(currNode->right, level+1));
                
        }
        
        for( auto i : levelMapping)
            ans.push_back(i.second);
        
        return ans;
        */
    }
};




