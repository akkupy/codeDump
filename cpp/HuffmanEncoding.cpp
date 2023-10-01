
// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
            data= d;
            left= NULL;
            right= NULL;
        }
};
class cmp{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }  
};
class Solution
{
	public:
	
	    void traverse(Node* top, vector<string>& ans, string temp){
	        if(top->left==NULL && top->right==NULL){
	            ans.push_back(temp);
	            return;
	        }
            
            traverse(top->left, ans, temp + '0');
            traverse(top->right, ans, temp + '1');
            
            
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>,  cmp> q;
		    
		    for(auto i : f){
		        q.push(new Node(i));
		    }
		    
		    while(q.size()>1){
		        
		        Node* a= q.top();
		        q.pop();
		        Node* b= q.top();
		        q.pop();
		        
		        Node* s= new Node(a->data + b->data);
		        s->left= a;
		        s->right= b;
		        
		        q.push(s);
		        
		    }
		    
		    Node* top= q.top();
		    q.pop();
		    
		    string temp= "";
		    vector<string> ans;
		    traverse(top, ans, temp);
		    
		    return ans;
		    
		}
};
