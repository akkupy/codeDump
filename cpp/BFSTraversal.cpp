
// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<queue>
#include<set>
#include<unordered_map>
void getAdjacentList(unordered_map<int, set<int>> &adj, vector<pair<int, int>> &edges){
    for(auto i : edges){
        adj[i.first].insert(i.second);
        adj[i.second].insert(i.first);
    }
}
void traverseBFS(unordered_map<int, set<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int i){
    queue<int> q;
    q.push(i);
    visited[i]= true;
    while(!q.empty()){
        int temp= q.front();
        q.pop();
        ans.push_back(temp);
        for(auto ele : adj[temp]){
            if(!visited[ele]){
                q.push(ele);
                visited[ele]= true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adj;
    getAdjacentList(adj, edges);
    vector<int> ans;
    unordered_map<int,bool> visited;

    // This is done if the graph is disconnected
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            traverseBFS(adj, visited, ans, i);
        }
    }
    return ans;
}