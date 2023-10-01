
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    void getLeftNodes(Node* root, vector<int> &ans){
        if(root==NULL)
            return;
        else if(root->left==NULL && root->right==NULL)
            return;
        
        ans.push_back(root->data);
        if(root->left){
            getLeftNodes(root->left, ans);
        }else{
            getLeftNodes(root->right, ans);
        }
        
    }
    void getRightNodes(Node* root, vector<int> &ans){
        if(root==NULL)
            return;
        else if(root->left==NULL && root->right==NULL)
            return;
        
        if(root->right){
            getRightNodes(root->right, ans);
        }else{
            getRightNodes(root->left, ans);
        }
        ans.push_back(root->data);
    }
    void getLeafNodes(Node* root, vector<int> &ans){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        getLeafNodes(root->left, ans);
        getLeafNodes(root->right, ans);
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        getLeftNodes(root->left, ans);
        getLeafNodes(root->left, ans);
        getLeafNodes(root->right, ans);
        getRightNodes(root->right, ans);
        
        return ans;
    }
};

