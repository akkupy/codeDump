
// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<unordered_map>
#include<list>
#include<queue>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    
    unordered_map<int, list<int>> adj;
    for(auto i : edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s]= true;
    parent[s]= -1;
    
    while(!q.empty()){
        int front= q.front();
        q.pop();
        
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i]= true;
                parent[i]= front;
                q.push(i);
            }
        }
    }
    
    vector<int> ans;
    int curr= t;
    ans.push_back(curr);
    while(curr!=s){
        curr= parent[curr];
        ans.push_back(curr);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}
