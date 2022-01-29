// Code : BFS Traversal
// Send Feedback
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.
// Note:
// 1. Here you need to consider that you need to print BFS path starting from vertex 0 only.
// 2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 3. E is the number of edges present in graph G.
// 4. Take graph input in the adjacency matrix.
// 5. Handle for Disconnected Graphs as well
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print the BFS Traversal, as described in the task.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// 0 1 3 2
#include <iostream>
#include <queue>
using namespace std;
class graph
{
    int **adj_matrix;
    int num_vertices;
    int num_edges;

public:
    graph() {}
    graph(int num_vertices, int num_edges)
    {
        this->num_vertices = num_vertices;
        this->num_edges = num_edges;
        adj_matrix = new int *[num_vertices];
        for (int i = 0; i < num_vertices; i++)
        {
            adj_matrix[i] = new int[num_vertices];
            for (int j = 0; j < num_vertices; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < num_edges; i++)
        {
            int first, second;
            cin >> first >> second;
            adj_matrix[first][second] = 1;
            adj_matrix[second][first] = 1;
        }
    }
    void print()
    {
        if (num_vertices == 0)
        {
            return;
        }
        bool *visited = new bool[num_vertices];
        for (int i = 0; i < num_vertices; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < num_vertices; i++)
        {
            queue<int> record;
            if (visited[i] == false)
            {
                record.push(i);
                visited[i] = true;
            }
            while (!record.empty())
            {
                cout << record.front() << " ";
                int temp = record.front();
                record.pop();
                for (int i = 0; i < num_vertices; i++)
                {
                    if (i == temp)
                    {
                        continue;
                    }
                    if (adj_matrix[temp][i] == 1 && visited[i] == false)
                    {
                        record.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
};
int main()
{
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    graph g1(num_vertices, num_edges);
    g1.print();
    return 0;
}