
// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0 

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void getNodes(TreeNode<int>* root, vector<TreeNode<int>*> &nodes) {
    if(root==NULL)
        return;

    getNodes(root->left, nodes);
    nodes.push_back(root);
    getNodes(root->right, nodes);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL)
        return root;
    vector<TreeNode<int>*> nodes;
    getNodes(root, nodes);
    
    TreeNode<int>* newNode= new TreeNode<int>(nodes[0]->data);
    newNode->left= NULL;
    
    TreeNode<int>* currNode= newNode;
    
    for(int i=1; i<nodes.size(); i++) {
        TreeNode<int>* tempNode= new TreeNode<int>(nodes[i]->data);
        tempNode->left=NULL;
        currNode->right= tempNode;
        currNode= tempNode;
    }
    
    
    
    return newNode;
}










