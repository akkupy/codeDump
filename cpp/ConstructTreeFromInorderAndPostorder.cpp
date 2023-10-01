
// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

//Function to return a tree created from postorder and inoreder traversals.
// int getPosition(int in[], int element, int n){
//     for(int i=0; i<n; i++){
//         if(in[i]==element){
//             in[i]=-1;
//             return i;
//         }
//     }
    
//     return -1;
// }
Node* constructTree(int in[], int pos[],int &index, int n,
                int inorderStart, int inorderEnd, map<int,queue<int>> &elementToIndex){
        
    if(index<0 || (inorderStart > inorderEnd))
        return NULL;
        
    int element= pos[index--];
    Node* root= new Node(element);
    int position= elementToIndex[element].front();
    elementToIndex[element].pop();
    // int position= getPosition(in, element, n);
    
    // first right then left because in postorder rule is LRN and we are traversing from end to start of postorder array
    root->right= constructTree(in, pos, index, n, position+1, inorderEnd, elementToIndex);
    root->left= constructTree(in, pos, index, n, inorderStart, position-1, elementToIndex);
               
    return root;
        
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex= n-1;
    
    map<int,queue<int>> elementToIndex;
    for(int i=0; i<n; i++){
        elementToIndex[in[i]].push(i);
    }
    
    Node* ans = constructTree(in, post, postOrderIndex, n, 0, n-1, elementToIndex);
        
    return ans;
    
}




