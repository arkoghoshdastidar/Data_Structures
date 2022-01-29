// Code : Is Connected ?
// Send Feedback
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
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
// true
// Sample Input 2:
// 4 3
// 0 1
// 1 3
// 0 3
// Sample Output 2:
// false
// Sample Output 2 Explanation
// The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2.
#include <iostream>
using namespace std;

class graph
{
private:
    int **adj_matrix;
    int num_nodes;
    int num_edges;
    void isConnectedHelper(int si, bool *visited)
    {
        visited[si] = true;
        for (int i = 0; i < this->num_nodes; i++)
        {
            if (i == si)
            {
                continue;
            }
            else if (adj_matrix[si][i] && !visited[i])
            {
                isConnectedHelper(i, visited);
            }
        }
    }

public:
    graph(int num_nodes, int num_edges)
    {
        this->num_nodes = num_nodes;
        this->num_edges = num_edges;
        adj_matrix = new int *[this->num_nodes];
        for (int i = 0; i < this->num_nodes; i++)
        {
            adj_matrix[i] = new int[this->num_nodes];
            for (int j = 0; j < this->num_nodes; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < this->num_edges; i++)
        {
            int first, second;
            cin >> first >> second;
            adj_matrix[first][second] = 1;
            adj_matrix[second][first] = 1;
        }
    }

    bool isConnected()
    {
        bool *visited = new bool[this->num_nodes];
        for (int i = 0; i < this->num_nodes; i++)
        {
            visited[i] = false;
        }
        isConnectedHelper(0, visited);
        for (int i = 0; i < this->num_nodes; i++)
        {
            if (visited[i] == false)
            {
                delete[] visited;
                return false;
            }
        }
        delete[] visited;
        return true;
    }
};

int main(void)
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    graph g1(num_nodes, num_edges);
    if (g1.isConnected())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}