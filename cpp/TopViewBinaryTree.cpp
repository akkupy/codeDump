
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,int> hdMapping;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<Node*,int> front= q.front();
            q.pop();
            Node* currNode= front.first;
            int hd= front.second;
            
            if(hdMapping.find(hd) ==  hdMapping.end())
                hdMapping[hd]= currNode->data;
            
            if(currNode->left)
                q.push(make_pair(currNode->left, hd-1));
            if(currNode->right)
                q.push(make_pair(currNode->right, hd+1));
                
        }
        
        for( auto i : hdMapping)
            ans.push_back(i.second);
        
        return ans;
    }

};


