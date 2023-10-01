
// https://practice.geeksforgeeks.org/problems/articulation-point-1/1

class Solution {
  public:
    int timer= 1;
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, int timeOfInsertion[], 
    int low[], set<int> &articulationPoint){
        
        visited[node]= true;
        timeOfInsertion[node]= low[node]= timer++;
        int child= 0;

        for(auto i: adj[node]){
            if(i == parent)
                continue;
            else if(!visited[i]){
                dfs(i, node, adj, visited, timeOfInsertion, low, articulationPoint);

                low[node]= min(low[node], low[i]);
                
                // denotes that bridge is present
                if(low[i]>=timeOfInsertion[node] && parent!=-1)
                    articulationPoint.insert(node);
                child++;
            }else{
                low[node]= min(low[node], low[i]);
            }

        }
        if(parent==-1 && child>1)
            articulationPoint.insert(node);

    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<bool> visited(V, false);
        int timeOfInsertion[V];
        int low[V];

        set<int> articulationPoint;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, -1, adj, visited, timeOfInsertion, low, articulationPoint);
            }
        }
        vector<int> ans(articulationPoint.begin(), articulationPoint.end());
        if(ans.size()==0)
            ans.push_back(-1);

        return ans;
    }
};