#include <climits>
#include <iostream>
using namespace std;
class graph
{
public:
    int num_nodes;
    int num_edges;
    int **adj_matrix;
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
            int first, second, weight;
            cin >> first >> second >> weight;
            adj_matrix[first][second] = weight;
            adj_matrix[second][first] = weight;
        }
    }
};

int main(void)
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    graph g(num_nodes, num_edges);
    int *parent = new int[num_nodes];
    int *weight = new int[num_nodes];
    for (int i = 0; i < num_nodes; i++)
    {
        if (i == 0)
        {
            weight[i] = 0;
            continue;
        }
        weight[i] = INT_MAX;
    }
    bool *visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    while (count < num_nodes)
    {
        int index = 0;
        int min_weight = INT_MAX;
        for (int i = 0; i < num_nodes; i++)
        {
            if (!visited[i] && weight[i] < min_weight)
            {
                index = i;
                min_weight = weight[i];
            }
        }
        visited[index] = true;
        for (int i = 0; i < num_nodes; i++)
        {
            if (g.adj_matrix[index][i] != 0 && !visited[i])
            {
                if (g.adj_matrix[index][i] < weight[i])
                {
                    parent[i] = index;
                    weight[i] = g.adj_matrix[index][i];
                }
            }
        }
        count++;
    }
    for (int i = 1; i < num_nodes; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " ";
        }
        else
        {
            cout << i << " " << parent[i] << " ";
        }
        cout << weight[i] << endl;
    }
    return 0;
}