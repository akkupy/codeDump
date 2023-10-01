
// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        
        Node* curr= root;
        Node* pre;
        
        while(curr!=NULL){
            
            if(curr->left){
                pre= curr->left;
                while(pre->right)
                    pre= pre->right;
                
                pre->right= curr->right;
                curr->right= curr->left;
                curr->left= NULL;
            }
            curr= curr->right;
        }
        
    }
};