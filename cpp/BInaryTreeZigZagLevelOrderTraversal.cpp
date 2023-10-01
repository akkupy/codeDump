
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        queue<TreeNode*> que;
        que.push(root);
        bool leftToRight= true;
        while(!que.empty()){

            int size= que.size();
            vector<int> tempAns(size);

            for(int i=0; i<size; i++){
                TreeNode* tempNode= que.front();
                que.pop();

                int index= leftToRight ? i : size-i-1;
                tempAns[index]= tempNode->val;

                if(tempNode->left)
                    que.push(tempNode->left);
                if(tempNode->right)
                    que.push(tempNode->right);

            }
            leftToRight= !leftToRight;
            ans.push_back(tempAns);
        }

        return ans;
    }
};





