
// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &egdes)
{
    
    unordered_map<int, list<pair<int, int>>> adj;

    for(auto i : egdes){
        int first= i.first.first;
        int second= i.first.second;
        int weight= i.second;
        
        adj[first].push_back(make_pair(second, weight));
        adj[second].push_back(make_pair(first, weight));

    }

    vector<int> keys(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++){
        keys[i]= INT_MAX;
        mst[i]= false;
        parent[i]= -1;
    }

    keys[1]= 0;

    for(int i=1; i<n; i++){
        int min= INT_MAX;
        int u;

        // To find the minimum node
        for(int v=1; v<=n; v++){
            if(mst[v]==false && min>keys[v]){
                min= keys[v];
                u= v;
            }
        }

        //mark the node as true
        mst[u]= true;

        //traverse and check its adjacent nodes
        for(auto neighbour: adj[u]){
            int v= neighbour.first;
            int w= neighbour.second;
            if(mst[v]==false && w<keys[v]){
                keys[v]= w;
                parent[v]= u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){
        ans.push_back(make_pair(make_pair(parent[i], i), keys[i]));
    }

    return ans;

}














