
// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=1

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.

    // Iterative Way
    while(root!=NULL){
        if(root->data==x)
            return true;
        else if(root->data>x)
            root=root->left;
        else
            root=root->right;
    }
    return false;

    /* Recursive Way 
    bool ans;
    if(root==NULL)
        return false;
    if(root->data==x) {
        return true;
    }
    else if(root->data<x){
        ans= searchInBST(root->right, x);
    }
    else{
        ans= searchInBST(root->left, x);
    }
    
    return ans;
    */
}


