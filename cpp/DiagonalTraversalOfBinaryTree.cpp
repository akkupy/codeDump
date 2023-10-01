
// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*> q;
   vector<int> ans;
   q.push(root);
  
   while(!q.empty()){
       Node* t=q.front();q.pop();
       while(t){
          ans.push_back(t->data);
          if(t->left)q.push(t->left);
          t=t->right;
       }
     
   }
  
   return ans;
   
}



