#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adj_list;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adj_list.resize(vertices);
    }

    // Function to adding an edge to graph
    void addEdge(int source, int destination) {
        adj_list[source].push_back(destination);
        adj_list[destination].push_back(source);
    }

    // Function to printing graph
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (const int& neighbor : adj_list[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Sample input for checking graph implementation
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
