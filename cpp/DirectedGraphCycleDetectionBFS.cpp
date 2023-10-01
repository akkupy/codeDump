
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<unordered_map>
#include<queue>
#include<list>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adj;
    for(auto i : edges){
        adj[i.first].push_back(i.second);
    }
    
    vector<int> inDegree(n+1,0);
    for(auto i : adj){
        for(auto j : i.second)
            inDegree[j]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(inDegree[i]==0)
            q.push(i);
    }
    
    int count= 0;
    
    while(!q.empty()){
        int front= q.front();
        q.pop();
        
        count++;
        
        for(auto i : adj[front]){
            inDegree[i]--;
            if(inDegree[i]==0)
                q.push(i);
        }
    }
    
    return count!=n;
    
}