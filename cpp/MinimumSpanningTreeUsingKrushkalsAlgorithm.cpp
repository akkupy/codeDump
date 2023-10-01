
// https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<algorithm>
void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0; i<n; i++){
    parent[i]= i;
    rank[i]= 0;
  }
}
int findParent(int node, vector<int> &parent){
  if(parent[node]==node){
    return node;
  }
  return parent[node]= findParent(parent[node], parent);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u= findParent(u, parent);
  v= findParent(v, parent);

  if(rank[u]<rank[v]){
    parent[u]= v;
  }
  else if (rank[u]>rank[v]){
    parent[v]= u;
  }
  else{
    parent[v]= u;
    rank[u]++;
  }

}
bool compare(vector<int> &a, vector<int> &b){
  return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), compare);
  vector<int> parent(n);
  vector<int> rank(n);
  
  makeSet(parent, rank, n);

  int minWeight= 0;

  for(int i=0; i<edges.size(); i++){

    int u= findParent(edges[i][0], parent);
    int v= findParent(edges[i][1], parent);
    
    if(u!=v){
      minWeight+= edges[i][2];
      unionSet(u, v, parent, rank);
    }

  }

  return minWeight;

}





