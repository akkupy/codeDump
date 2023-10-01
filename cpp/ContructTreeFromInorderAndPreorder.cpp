
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

class Solution{
    public:
    // int getPosition(int in[], int element, int n){
    //     for(int i=0; i<n; i++){
    //         if(in[i]==element){
    //             in[i]=-1;
    //             return i;
    //         }
    //     }
        
    //     return -1;
    // }
    Node* constructTree(int in[], int pre[], int &index, int n,
                    int inorderStart, int inorderEnd, map<int,queue<int>> &elementToIndex){
            
        if(index>=n || (inorderStart > inorderEnd))
            return NULL;
            
        int element= pre[index++];
        Node* root= new Node(element);
        int position= elementToIndex[element].front();
        elementToIndex[element].pop();
        //int position= getPosition(in, element, n);
        
        // first left then right because in preorder rule is NLR and we are traversing from start to end of preorder array
        root->left= constructTree(in, pre, index, n, inorderStart, position-1, elementToIndex);
        root->right= constructTree(in, pre, index, n, position+1, inorderEnd, elementToIndex);
                   
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,queue<int>> elementToIndex;
        for(int i=0; i<n; i++){
            elementToIndex[in[i]].push(i);
        }
        int index= 0;
        Node* ans = constructTree(in, pre, index, n, 0, n-1, elementToIndex);
        
        return ans;
    }
};



