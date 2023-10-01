
// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=1

#include<unordered_map>
#include<list>
#include<stack>
void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &topo){
	visited[node]= true;
	for(auto i : adj[node]){
		if(!visited[i]){
			dfs(i, adj, visited, topo);
		}
	}
	topo.push(node);
}
void revDfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited){
	visited[node]= true;
	for(auto i : adj[node]){
		if(!visited[i])
			revDfs(i, adj, visited);
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
	unordered_map<int, list<int>> transpose;
	for(auto i : edges){
		adj[i[0]].push_back(i[1]);
		transpose[i[1]].push_back(i[0]);
	}
	
	vector<bool> visited(v, false);
	stack<int> topo;

	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfs(i, adj, visited, topo);
		}
	}

	for(int i=0; i<v; i++)
		visited[i]= false;

	int count= 0;

	while(!topo.empty()){
		int top= topo.top();
		topo.pop();
		if(!visited[top]){
			count++;
			revDfs(top, transpose, visited);
		}
	}

	return count;

}










