#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template <typename T>
class Graph{
    public:
        unordered_map<T,list<T>> edges;
        
        void insert(T firstEdgeElement, T secondEdgeElement, bool direction){
            if(direction){
                edges[firstEdgeElement].push_back(secondEdgeElement);
            }else{
                edges[firstEdgeElement].push_back(secondEdgeElement);
                edges[secondEdgeElement].push_back(firstEdgeElement);
            }
        }

        void print(){
            for(auto i : edges){
                cout<<i.first<<" -> ";
                for(auto j: i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

};

int main(){

    Graph<int> graph;
    int inputFirstEdge=0;
    int inputSecondEdge=0;
    bool directedOrUndirected;

    while(inputFirstEdge>-1){
        cin>>inputFirstEdge;
        if(inputFirstEdge>-1){
            cin>>inputSecondEdge;
            cin>>directedOrUndirected;
            graph.insert(inputFirstEdge, inputSecondEdge, directedOrUndirected);
        }
    }

    graph.print();

    return 0;
}
