#include<iostream>
#include<list>
#include<limits.h>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;
class Graph{
    public :
        unordered_map<int, list<pair<int,int>>> adj;
        stack<int> topo;

        void insert(int parent, int adjacent, int weight){
            adj[parent].push_back(make_pair(adjacent, weight));
        }

        void printGraph(){
            for (auto i : adj)
            {
                cout<<i.first<<" -> ";
                for (auto neighbour: i.second)
                {
                    cout<<"("<<neighbour.first<<", "<<neighbour.second<<"), ";
                }
                cout<<endl;
            }
        }
    
        void topoSortUsingDFS(int node, unordered_map<int, bool> &visited){
            visited[node]= true;

            for (auto neighbour: adj[node])
            {
                if (!visited[neighbour.first])
                {
                    topoSortUsingDFS(neighbour.first, visited);
                }
            }
            topo.push(node);
        }

        void getDistance(int startPoint){
            vector<int> distance(6);
            
            for (int i = 0; i < 6; i++)
            {
                distance[i]= INT_MAX;
            }

            distance[startPoint]= 0;

            while(!topo.empty()){
                int node= topo.top();
                topo.pop();

                if(distance[node]!=INT_MAX){
                    for(auto i : adj[node]){
                        int currDistance= distance[node] + i.second;
                        if (currDistance < distance[i.first])
                        {
                            distance[i.first]= currDistance;
                        }
                    }
                }
            }

            for (auto i : distance)
            {
                cout<<i<<" ";
            }
            
            
        }

};
int main(){
    Graph g;
    g.insert(0,1,5);
    g.insert(0,2,3);
    g.insert(1,2,2);
    g.insert(1,3,6);
    g.insert(2,3,7);
    g.insert(2,4,4);
    g.insert(2,5,2);
    g.insert(3,4,-1);
    g.insert(4,5,-2);

    g.printGraph();
    
    unordered_map<int, bool> visited;

    for(int i=0; i<6; i++){
        if(!visited[i]){
            g.topoSortUsingDFS(i, visited);
        }
    }

    g.getDistance(1);

    return 0;
}