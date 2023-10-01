
// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)
            return ans;
        map<int, vector<int>> hdMapping;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> front= q.front();
            q.pop();
            Node* temp= front.first;
            int hd= front.second;

            hdMapping[hd].push_back(temp->data);


            if(temp->left)
                q.push(make_pair(temp->left, hd-1));
            if(temp->right)
                q.push(make_pair(temp->right, hd+1));

        }

        for(auto i : hdMapping){
            ans.insert(ans.end(), i.second.begin(), i.second.end());
        }
        
        return ans;
    }
};

