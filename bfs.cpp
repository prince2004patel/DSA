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

    void BFS(int startVertex)
    {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = -1, rear = -1;

        // Mark the current node as visited and enqueue it
        visited[startVertex] = true;
        queue[++rear] = startVertex;

        cout << "Breadth-First Search starting from vertex " << startVertex << ": ";

        while (front != rear)
        {
            // Dequeue a vertex from the queue and print it
            int currentVertex = queue[++front];
            cout << currentVertex << " ";

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (int i = 0; i < vertices; ++i)
            {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    queue[++rear] = i;
                }
            }
        }

        cout << endl;
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

    // Perform BFS starting from vertex 2
    graph.BFS(2);

    return 0;
}
