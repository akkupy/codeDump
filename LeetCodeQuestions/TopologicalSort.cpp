//TOPOLOGICAL SORT USING BOTH BFS AND DFS.

class Solution
{
	public:
	//USING BFS
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
		vector<int> indegree(V, 0);
		vector<int> ans;
		for(int i=0;i<V;i++)
		{
			for(auto &x : adj[i])
				indegree[x]++;
		}
		queue<int> q;
		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
				q.push(i);
		}
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for(auto &x : adj[node])
			{
				indegree[x]--;
				if(indegree[x]==0)
					q.push(x);
			}
		}
		return ans;
	}

/*	USING DFS
    void dfs(vector<int> adj[], vector<int> &viz, int &i, stack<int> &s)
    {
        viz[i]=1;
        for(auto &x : adj[i])
        {
            if(!viz[x])
                dfs(adj, viz, x, s);
        }
        s.push(i);
    }
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> viz(V, 0);
	    vector<int> ans;
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(!viz[i])
	            dfs(adj, viz, i, s);
	    }
	    while(!s.empty())
	    {
	        int node = s.top();
	        s.pop();
	        ans.push_back(node);
	    }
	    return ans;
	}
*/
};