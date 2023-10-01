
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
void topoSort(int i, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s){
    visited[i]= true;
    for(auto ele : adj[i]){
        if(!visited[ele])
            topoSort(ele, adj, visited, s);
    }
    
    s.push(i);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int, list<int>> adj;
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }
    
//     vector<bool> visited(v);
//     stack<int> s;
//     for(int i=0; i<v; i++){
//         if(!visited[i]){
//             topoSort(i, adj, visited, s);
//         }
//     }
    
//     vector<int> ans;
//     while(!s.empty()){
//         ans.push_back(s.top());
//         s.pop();
//     }
    
    // BFS Solution using Kahn's Algorithm
    vector<int> inDegree(v,0);
    for(auto i : adj){
        for(auto j : i.second)
            inDegree[j]++;
    }
    
    queue<int> q;
    for(int i=0; i<v; i++){
        if(inDegree[i]==0)
            q.push(i);
    }
    
    vector<int> ans;
    
    while(!q.empty()){
        int front= q.front();
        q.pop();
        ans.push_back(front);
        for(auto i : adj[front]){
            inDegree[i]--;
            if(inDegree[i]==0)
                q.push(i);
        }
    }
    
    
    return ans;
}