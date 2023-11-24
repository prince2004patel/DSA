#include <iostream>

using namespace std;

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

class Graph
{
public:
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    Graph(int v)
    {
        vertices = v;
        for (int i = 0; i < MAX_VERTICES; ++i)
        {
            for (int j = 0; j < MAX_VERTICES; ++j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w)
    {
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;
    }

    void DFS(int startVertex)
    {
        bool visited[MAX_VERTICES] = {false};
        DFSUtil(startVertex, visited);
        cout << endl;
    }

private:
    void DFSUtil(int vertex, bool visited[])
    {
        // Mark the current node as visited and print it
        visited[vertex] = true;
        cout << vertex << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < vertices; ++i)
        {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }
};

int main()
{
    // Create a sample graph
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform DFS starting from vertex 2
    graph.DFS(2);

    return 0;
}
