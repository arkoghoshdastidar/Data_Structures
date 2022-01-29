#include <iostream>
using namespace std;
class graph
{
    int number_of_nodes;
    int number_of_edges;
    int **adjacency_matrix;
    void print_dfs(int starting_label, bool *visited)
    {
        cout << starting_label << endl;
        visited[starting_label] = true;
        for (int i = 0; i < number_of_nodes; i++)
        {
            if (i == starting_label)
            {
                continue;
            }
            if (adjacency_matrix[starting_label][i] == 1)
            {
                if (visited[i] == false)
                {
                    print_dfs(i, visited);
                }
                else
                {
                    continue;
                }
            }
        }
    }

public:
    graph() {}
    graph(int number_of_nodes, int number_of_edges)
    {
        this->number_of_nodes = number_of_nodes;
        this->number_of_edges = number_of_edges;
        adjacency_matrix = new int *[number_of_nodes];
        for (int i = 0; i < number_of_nodes; i++)
        {
            adjacency_matrix[i] = new int[number_of_nodes];
        }
        for (int i = 0; i < number_of_nodes; i++)
        {
            for (int j = 0; j < number_of_nodes; j++)
            {
                adjacency_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < number_of_edges; i++)
        {
            int first_vertix, second_vertix;
            cin >> first_vertix >> second_vertix;
            adjacency_matrix[first_vertix][second_vertix] = 1;
            adjacency_matrix[second_vertix][first_vertix] = 1;
        }
    }
    ~graph()
    {
        for (int i = 0; i < number_of_nodes; i++)
        {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
    }
    void print_dfs()
    {
        bool *visited = new bool[number_of_nodes];
        for (int i = 0; i < number_of_nodes; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < number_of_nodes; i++)
        {
            if (visited[i] == false)
            {
                print_dfs(i, visited);
            }
        }
        delete[] visited;
    }
};