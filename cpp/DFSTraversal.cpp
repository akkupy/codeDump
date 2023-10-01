
// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<list>
#include<unordered_map>
void getAdjacentList(vector<vector<int>> &edges, unordered_map<int,list<int>> &adj){
    for(auto i : edges){
        int first= i[0];
        int second= i[1];
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
}
void dfs(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &temp, int i){
    temp.push_back(i);
    visited[i]= true;
    for(auto ele : adj[i]){
        if(!visited[ele]){
            dfs(adj, visited, temp, ele);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    getAdjacentList(edges, adj);
    unordered_map<int, bool> visited;
    
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(adj, visited, temp, i);
            ans.push_back(temp);
        }
    }
    
    return ans;
}