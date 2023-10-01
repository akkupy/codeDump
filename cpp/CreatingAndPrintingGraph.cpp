
// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> ans(n);
    
    for(auto i : edges){
        int first= i[0];
        int second= i[1];
                
        ans[first].push_back(second);
        ans[second].push_back(first);
    }
    
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        adj[i].insert(adj[i].end(), ans[i].begin(), ans[i].end());
    }
    
    
    return adj;
}