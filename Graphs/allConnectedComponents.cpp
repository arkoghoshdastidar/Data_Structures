// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1
// 2 3
// Sample Input 2:
// 4 3
// 0 1
// 1 3
// 0 3
// Sample Output 2:
// 0 1 3
// 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class graph
{
private:
    int **adj_matrix;
    int num_nodes;
    int num_edges;
    vector<int> connectedComponent(int si, bool *visited, vector<int> smallAns)
    {
        smallAns.push_back(si);
        visited[si] = true;
        for (int i = 0; i < num_nodes; i++)
        {
            if (i == si)
            {
                continue;
            }
            else if (adj_matrix[si][i] == 1 && visited[i] == false)
            {
                smallAns = connectedComponent(i, visited, smallAns);
            }
        }
        return smallAns;
    }

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
            int first, second;
            cin >> first >> second;
            adj_matrix[first][second] = 1;
            adj_matrix[second][first] = 1;
        }
    }
    vector<int> sort(vector<int> smallAns)
    {
        priority_queue<int, vector<int>, greater<int>> bucket;
        while (smallAns.size() != 0)
        {
            bucket.push(smallAns.back());
            smallAns.pop_back();
        }
        while (!bucket.empty())
        {
            smallAns.push_back(bucket.top());
            bucket.pop();
        }
        return smallAns;
    }
    vector<vector<int>> connectedComponents()
    {
        bool *visited = new bool[num_nodes];
        for (int i = 0; i < num_nodes; i++)
        {
            visited[i] = false;
        }
        vector<vector<int>> answer;
        for (int i = 0; i < num_nodes; i++)
        {
            if (visited[i] == false)
            {
                vector<int> smallAns;
                smallAns = connectedComponent(i, visited, smallAns);
                smallAns = sort(smallAns);
                answer.push_back(smallAns);
            }
            else
            {
                continue;
            }
        }
        delete[] visited;
        return answer;
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
int main()
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    graph g1(num_nodes, num_edges);
    vector<vector<int>> answer = g1.connectedComponents();
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}