
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void storeLeftNodeValues(Node* root, int level, vector<int> &ans){

    if(root==NULL)
        return;
    
    if(level==ans.size())
        ans.push_back(root->data);
        
    storeLeftNodeValues(root->left, level+1, ans);
    storeLeftNodeValues(root->right, level+1, ans);

}

vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> ans;
   storeLeftNodeValues(root, 0, ans);
   
   return ans;
   
    /*
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,int> levelMapping;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        
        pair<Node*,int> front= q.front();
        q.pop();
        Node* currNode= front.first;
        int level= front.second;
        
        if(levelMapping.find(level) ==  levelMapping.end())
            levelMapping[level]= currNode->data;
        
        if(currNode->left)
            q.push(make_pair(currNode->left, level+1));
        if(currNode->right)
            q.push(make_pair(currNode->right, level+1));
            
    }
    
    for( auto i : levelMapping)
        ans.push_back(i.second);
    
    return ans;
    */
    
}

