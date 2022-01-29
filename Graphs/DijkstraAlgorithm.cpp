// Code : Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
// Note : Order of vertices in output doesn't matter.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5
#include <iostream>
#include <climits>
using namespace std;
class graph
{
    int num_nodes;
    int num_edges;
    int **adj_matrix;

public:
    graph(int num_nodes, int num_edges)
    {
        this->num_nodes = num_nodes;
        this->num_edges = num_edges;
        adj_matrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++)
        {
            adj_matrix[i] = new int[num_nodes];
            for (int j = 0; j < num_nodes; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < num_edges; i++)
        {
            int first, second, weigth;
            cin >> first >> second >> weigth;
            adj_matrix[first][second] = weigth;
            adj_matrix[second][first] = weigth;
        }
    }
    int *getDistance()
    {
        bool *visited = new bool[num_nodes];
        for (int i = 0; i < num_nodes; i++)
        {
            visited[i] = false;
        }
        int *dist = new int[num_nodes];
        for (int i = 0; i < num_nodes; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[0] = 0;
        int count = 0;
        while (count < num_nodes)
        {
            int index = -1;
            for (int i = 0; i < num_nodes; i++)
            {
                if (index == -1 && !visited[i])
                {
                    index = i;
                    continue;
                }
                if (!visited[i] && dist[i] < dist[index])
                {
                    index = i;
                }
            }
            visited[index] = true;
            for (int i = 0; i < num_nodes; i++)
            {
                if (!visited[i] && adj_matrix[i][index] != 0)
                {
                    int tempDist = dist[index] + adj_matrix[index][i];
                    if (tempDist < dist[i])
                    {
                        dist[i] = tempDist;
                    }
                }
            }
            count++;
        }
        return dist;
    }
    ~graph()
    {
        for (int i = 0; i < num_nodes; i++)
        {
            delete[] adj_matrix[i];
        }
        delete[] adj_matrix;
    }
};
int main(void)
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    graph g(num_nodes, num_edges);
    int *dist = g.getDistance();
    for (int i = 0; i < num_nodes; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    delete[] dist;
    return 0;
}