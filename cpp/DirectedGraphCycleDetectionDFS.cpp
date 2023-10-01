
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<unordered_map>
#include<list>
bool cycleDFS(int i, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
    visited[i]= true;
    dfsVisited[i]= true;
    
    for(auto ele : adj[i]){
        if(!visited[ele]){
            bool check= cycleDFS(ele, visited, dfsVisited, adj);
            if(check)
                return true;
        }
        else if(dfsVisited[ele]){
            return true;
        }
    }
    
    visited[i]= false;
    dfsVisited[i]= false;
    return false;
    
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adj;
    for(auto i : edges){
        adj[i.first].push_back(i.second);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool check= cycleDFS(i, visited, dfsVisited, adj);
            if(check)
                return true;
        }
    }
    return false;
}