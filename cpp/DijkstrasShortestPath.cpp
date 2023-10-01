
// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<limits.h>
#include<unordered_map>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adj;

    for(auto i : vec){

        int first= i[0];
        int second= i[1];
        int weight= i[2];

        adj[first].push_back(make_pair(second, weight));
        adj[second].push_back(make_pair(first, weight));

    }

    vector<int> distance(vertices);
    for(int i=0; i<vertices; i++)
        distance[i]= INT_MAX;

    set<pair<int,int>> s;
    distance[source]= 0;
    s.insert(make_pair(0, source));

    while(!s.empty()){
        auto top = *(s.begin());

        int dis= top.first;
        int node= top.second;

        s.erase(s.begin());

        for(auto neighbour : adj[node]){
            int currDis= dis + neighbour.second;
            if(currDis<distance[neighbour.first]){

                auto entryPresent= s.find(make_pair(distance[neighbour.first],neighbour.first));

                if(entryPresent != s.end()){
                    s.erase(entryPresent);
                }

                distance[neighbour.first]= currDis;

                s.insert(make_pair(distance[neighbour.first], neighbour.first));

            }
            

        }

    }

    return distance;


}
