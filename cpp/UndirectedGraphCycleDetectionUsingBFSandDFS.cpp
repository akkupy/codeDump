
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<queue>
#include<unordered_map>
#include<list>
bool cycleBFS(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, int i){
    unordered_map<int,int> parent;
    parent[i]=-1;
    queue<int> q;
    q.push(i);
    visited[i]= true;
    while(!q.empty()){
        int temp= q.front();
        q.pop();
        for(auto ele : adj[temp]){
            if(parent[temp]!=ele && visited[ele]){
                return true;
            }
            else if(!visited[ele]){
                q.push(ele);
                visited[ele]= true;
                parent[ele]= temp;
            }
        }
    }
    return false;
}
bool cycleDFS(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, int parent, int i){
    visited[i]= true;
    for(auto ele : adj[i]){
        if(!visited[ele]){
            bool check= cycleDFS(adj, visited, i, ele);
            if(check)
                return true;
        }
        else if(ele!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    for(auto i : edges){
        int first= i[0];
        int second= i[1];
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
    unordered_map<int,bool> visited;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            // bool check= cycleBFS(adj, visited, i);
            bool check= cycleDFS(adj, visited, -1, i);
            if(check)
                return "Yes";
        }
    }
    return "No";
}
