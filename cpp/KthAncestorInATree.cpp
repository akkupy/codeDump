
// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

void findKthAncestor(Node* root, int &k, int &node, int &ancestor, bool &found){
    if(root==NULL)
        return;
    if(root->data==node){
        found= true;
        return;
    }
    
    findKthAncestor(root->left, k, node, ancestor, found);
    findKthAncestor(root->right, k, node, ancestor, found);
    
    if(found){
        k--;
        if(k<0)
            ancestor= root->data;
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    bool found= false;
    int ancestor= 0;
    findKthAncestor(root, k, node, ancestor, found);
    if(found && ancestor!=0)
        return ancestor;
    return -1;
}
