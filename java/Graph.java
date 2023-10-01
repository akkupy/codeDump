import java.util.*;

class Graph {
    private int V; // Number of vertices
    private LinkedList<Integer> adjList[]; // Adjacency list

    // Constructor
    Graph(int v) {
        V = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adjList[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adjList[v].add(w);
    }

    // Depth-First Search starting from a given vertex
    void DFS(int v) {
        boolean visited[] = new boolean[V]; // Mark all vertices as not visited

        // Call the recursive helper function to perform DFS
        DFSUtil(v, visited);
    }

    // Recursive function to perform DFS
    private void DFSUtil(int v, boolean visited[]) {
        visited[v] = true; // Mark the current vertex as visited
        System.out.print(v + " "); // Print the current vertex

        // Recur for all the vertices adjacent to this vertex
        for (Integer neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    public static void main(String args[]) {
        Graph g = new Graph(7);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(2, 6);

        System.out.println("Depth-First Traversal (starting from vertex 0): ");
        g.DFS(0);
    }
}
