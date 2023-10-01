
// https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?leftPanelTab=1

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> distance(n+1, 1e9);

    distance[src]= 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u= edges[j][0];
            int v= edges[j][1];
            int wt= edges[j][2];
            if(distance[u]!=1e9 && ((distance[u] + wt)<distance[v]))
                distance[v]= distance[u] + wt;
        }
    }

    return distance[dest];

}