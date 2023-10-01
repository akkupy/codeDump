
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/874863877/

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
    void getElements(TreeNode* root, vector<int> &elements) {
        if(root==NULL)
            return;

        getElements(root->left, elements);
        elements.push_back(root->val);
        getElements(root->right, elements);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> elements;
        getElements(root, elements);

        int i=0, j=elements.size()-1;

        while(i<j){

            if(elements[i]+elements[j]>k)
                j--;
            else if(elements[i]+elements[j]<k)
                i++;
            else
                return true;

        }
        
        return false;
    }
};









