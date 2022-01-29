#include <iostream>
#include <vector>
using namespace std;

class graph
{
private:
    int **adj_matrix;
    int nodes;
    int edges;

public:
    graph(int nodes, int edges)
    {
        this->nodes = nodes;
        this->edges = edges;
        adj_matrix = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            adj_matrix[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < edges; i++)
        {
            int first, second;
            cin >> first >> second;
            adj_matrix[first][second] = 1;
            adj_matrix[second][first] = 1;
        }
    }

    int threeCycles(int si, bool *visited)
    {
        int count = 0;
        visited[si] = true;
        vector<int> adj_vertices;
        for (int i = 0; i < nodes; i++)
        {
            if (adj_matrix[si][i] && !visited[i])
            {
                adj_vertices.push_back(i);
            }
        }
        cout << si << " : ";
        for (int i = 0; i < adj_vertices.size(); i++)
        {
            cout << adj_vertices.at(i) << " ";
        }
        cout << endl;
        for (int i = 0; i < adj_vertices.size() - 1; i++)
        {
            for (int j = i + 1; j < adj_vertices.size(); j++)
            {
                if (adj_matrix[adj_vertices.at(i)][adj_vertices.at(j)])
                {
                    count++;
                }
            }
        }
        for (int i = 0; i < adj_vertices.size(); i++)
        {
            if (!visited[adj_vertices.at(i)])
            {
                count += threeCycles(adj_vertices.at(i), visited);
            }
        }
        return count;
    }

    int threeCycles()
    {
        if (edges < 3)
        {
            return 0;
        }
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }
        int count = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                count += threeCycles(i, visited);
            }
        }
        return count;
    }
};

int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;
    graph g(nodes, edges);
    cout << g.threeCycles() << endl;
    return 0;
}