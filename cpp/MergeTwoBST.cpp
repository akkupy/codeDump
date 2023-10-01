
// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void getElements(TreeNode<int>* root, vector<int> &elements){
    if(root==NULL)
        return;
    
    getElements(root->left, elements);
    elements.push_back(root->data);
    getElements(root->right, elements);
    
}

vector<int> merge(vector<int> &ele1, vector<int> &ele2){
    int i=0, j=0;
    vector<int> mergedList;
    while(i<ele1.size() && j<ele2.size()){
        if(ele1[i]<ele2[j]){
            mergedList.push_back(ele1[i++]);
        }else{
            mergedList.push_back(ele2[j++]);
        }
    }
    
    while(i<ele1.size()){
        mergedList.push_back(ele1[i++]);
    }
    
    while(j<ele2.size()){
        mergedList.push_back(ele2[j++]);
    }
    return mergedList;
}

TreeNode<int>* buildTree(int start, int end, vector<int> &elements){
    if(start>end)
        return NULL;
    
    int mid= (start+end)/2;
    TreeNode<int>* newNode= new TreeNode<int>(elements[mid]);
    newNode->left= buildTree(start, mid-1, elements);
    newNode->right= buildTree(mid+1, end, elements);
    
    return newNode;
    
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    
    vector<int> ele1;
    vector<int> ele2;
    getElements(root1, ele1);
    getElements(root2, ele2);
    
    vector<int> mergedElements= merge(ele1, ele2);
    
    return buildTree(0, mergedElements.size()-1, mergedElements);
    
}






