
// https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
public:
    int timer= 1;
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, int timeOfInsertion[], int low[], vector<vector<int>> &bridges){
        
        visited[node]= true;
        timeOfInsertion[node]= low[node]= timer++;

        for(auto i: adj[node]){
            if(i == parent)
                continue;
            else if(!visited[i]){
                dfs(i, node, adj, visited, timeOfInsertion, low, bridges);

                low[node]= min(low[node], low[i]);
                
                // denotes that bridge is present
                if(low[i]>timeOfInsertion[node])
                    bridges.push_back({i, node});
            }else{
                low[node]= min(low[node], low[i]);
            }

        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto i : connections){
            int first= i[0];
            int second= i[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        vector<bool> visited(n, false);
        int timeOfInsertion[n];
        int low[n];

        vector<vector<int>> bridges;

        dfs(0, -1, adj, visited, timeOfInsertion, low, bridges);

        return bridges;
    }
};