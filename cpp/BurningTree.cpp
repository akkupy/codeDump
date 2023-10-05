
// https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL)
            return 0;
        map<Node*, Node*> childToParent;
        map<Node*, bool> visited;
        queue<Node*> q;
        Node* targetNode= NULL;
        q.push(root);
        childToParent[root]= NULL;
        // To store childToParent mapping and get the targetNode
        while(!q.empty()){
            
            int size= q.size();
            
            for(int i=0; i<size; i++){
                Node* tempNode= q.front();
                q.pop();
                visited[tempNode]= false;
                if(tempNode->data==target)
                    targetNode= tempNode;
                if(tempNode->left){
                    q.push(tempNode->left);
                    childToParent[tempNode->left]= tempNode;
                }
                if(tempNode->right){
                    q.push(tempNode->right);
                    childToParent[tempNode->right]= tempNode;
                }
            }
        }
        
        int count= 0;
        q.push(targetNode);
        visited[targetNode]= true;
        bool inserted= false;
        
        while(!q.empty()){
            inserted= false;
            int size= q.size();
            for(int i=0; i<size; i++){
                Node* tempNode= q.front();
                q.pop();
                
                if(tempNode->left && !visited[tempNode->left]){
                    q.push(tempNode->left);
                    visited[tempNode->left]= true;
                    inserted= true;
                }
                if(tempNode->right && !visited[tempNode->right]){
                    q.push(tempNode->right);
                    visited[tempNode->right]= true;
                    inserted= true;
                }
                
                if(childToParent[tempNode] && !visited[childToParent[tempNode]]){
                    q.push(childToParent[tempNode]);
                    visited[childToParent[tempNode]]= true;
                    inserted= true;
                }
            }
            if(inserted)
                count++;

        }
        
        return count;
    }
};




