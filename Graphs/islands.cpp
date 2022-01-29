// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print the count the number of connected groups of islands
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V-1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 5 8
// 0 1
// 0 4
// 1 2
// 2 0
// 2 4
// 3 0
// 3 2
// 4 3
// Sample Output 1:
// 1
#include <iostream>
using namespace std;

class island
{
private:
    int **adj_matrix;
    int num_island;
    int num_routes;

public:
    island(int num_island, int num_routes)
    {
        this->num_island = num_island;
        this->num_routes = num_routes;
        adj_matrix = new int *[num_island];
        for (int i = 0; i < num_island; i++)
        {
            adj_matrix[i] = new int[num_island];
            for (int j = 0; j < num_island; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < num_routes; i++)
        {
            int first, second;
            cin >> first >> second;
            adj_matrix[first][second] = 1;
            adj_matrix[second][first] = 1;
        }
    }
    ~island()
    {
        for (int i = 0; i < num_island; i++)
        {
            delete[] adj_matrix[i];
        }
        delete[] adj_matrix;
    }
    void dfs(int si, bool *visited)
    {
        visited[si] = true;
        for (int i = 0; i < num_island; i++)
        {
            if (i == si)
            {
                continue;
            }
            else if (adj_matrix[si][i] == 1 && visited[i] == false)
            {
                dfs(i, visited);
            }
        }
    }
    int connectedComponentNum()
    {
        bool *visited = new bool[num_island];
        for (int i = 0; i < num_island; i++)
        {
            visited[i] = false;
        }
        int count = 0;
        for (int i = 0; i < num_island; i++)
        {
            if (visited[i] == false)
            {
                dfs(i, visited);
                count += 1;
            }
        }
        return count;
    }
};

int main(void)
{
    int ni, nr;
    cin >> ni >> nr;
    island isld1(ni, nr);
    cout << isld1.connectedComponentNum() << endl;
    return 0;
}