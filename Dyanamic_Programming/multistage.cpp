#include <iostream>
#include <climits>
using namespace std;

int min_cost(int, int, int, int);

class graph
{
private:
    int vertices;
    int edges;
    int **data;

public:
    graph(int vertices, int edges)
    {
        this->vertices = vertices;
        this->edges = edges;
        data = new int *[this->vertices];
        for (int i = 0; i < this->vertices; i++)
        {
            data[i] = new int[this->vertices];
            for (int j = 0; j < this->vertices; j++)
            {
                data[i][j] = 0;
            }
        }
        for (int i = 0; i < this->edges; i++)
        {
            int first, second, cost;
            cin >> first >> second >> cost;
            data[first][second] = cost;
        }
    }

    int min_cost(int current_stage, int current_value, int final_stage, int final_value, int **output)
    {
        if (current_stage == final_stage && current_value == final_value)
        {
            return 0;
        }
        else if (current_stage == final_stage && current_value != final_value)
        {
            return INT_MAX;
        }
        if (output[current_stage][current_value] != -1)
        {
            return output[current_stage][current_value];
        }
        int path_length = INT_MAX;
        for (int i = 0; i < this->vertices; i++)
        {
            if (data[current_value][i] != 0)
            {
                int temp_path = min_cost(current_stage + 1, i, final_stage, final_value, output);
                if (temp_path != INT_MAX)
                {
                    path_length = min(path_length, temp_path + data[current_value][i]);
                }
            }
        }
        output[current_stage][current_value] = path_length;
        return path_length;
    }
};

int main(void)
{
    graph g(12, 20);
    int **output = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        output[i] = new int[12];
        for (int j = 0; j < 12; j++)
        {
            output[i][j] = -1;
        }
    }
    cout << g.min_cost(1, 0, 5, 11, output) << endl;
    return 0;
}

// 0 1 9
// 0 2 7
// 0 3 3
// 0 4 2
// 1 5 4
// 1 6 2
// 1 7 1
// 2 5 2
// 2 6 7
// 3 7 11
// 4 7 8
// 5 8 5
// 5 9 6
// 6 8 4
// 6 9 3
// 7 9 5
// 7 10 6
// 8 11 4
// 9 11 2
// 10 11 5