
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        map<int, vector<int>> hdMapping;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            
            int size= q.size();
            map<int, vector<int>> tempHdMapping;

            for(int i=0; i<size; i++){
                pair<TreeNode*,int> front= q.front();
                q.pop();
                TreeNode* node= front.first;
                int hd= front.second;
                tempHdMapping[hd].push_back(node->val);
                if(node->left)
                    q.push(make_pair(node->left, hd-1));
                if(node->right)
                    q.push(make_pair(node->right, hd+1));
            }

            for(auto i : tempHdMapping){
                sort(i.second.begin(), i.second.end());
                hdMapping[i.first].insert(hdMapping[i.first].end(), i.second.begin(), i.second.end());
            }

        }

        for(auto i : hdMapping){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};















