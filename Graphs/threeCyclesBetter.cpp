#include <iostream>
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
        adj_matrix = new int *[this->nodes];
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

    int threeCycle()
    {
        int count = 0;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (adj_matrix[i][j])
                {
                    for (int k = 0; k < nodes; k++)
                    {
                        if (k == i || k == j)
                        {
                            continue;
                        }
                        else if (adj_matrix[j][k] && adj_matrix[i][k])
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count / 6;
    }
};
int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;
    graph g(nodes, edges);
    cout << g.threeCycle() << endl;
    return 0;
}