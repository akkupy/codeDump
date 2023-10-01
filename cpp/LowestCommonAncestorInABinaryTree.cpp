
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        //Your code here 
        if(root==NULL)
            return NULL;
        
        if(root->data==n1 || root->data==n2)
            return root;
            
        Node* left= lca(root->left, n1, n2);
        Node* right= lca(root->right, n1, n2);
        
        if(left==NULL && right==NULL)
            return NULL;
        else if(left==NULL && right!=NULL)
            return right;
        else if(left!=NULL && right==NULL)
            return left;
        else 
            return root;
        
    }
};

