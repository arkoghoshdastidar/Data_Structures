// Code : Has Path
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= 1000
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= V - 1
// 0 <= v2 <= V - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// true
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false
#include <iostream>
using namespace std;
class graph
{
    private:
    	int **adj_matrix;
    	int num_nodes;
    	int num_edges;
    public:
    	graph(){}
    	graph(int num_nodes, int num_edges)
        {
            this->num_nodes = num_nodes;
            this->num_edges = num_edges;
            adj_matrix = new int*[num_nodes];
            for(int i=0; i<num_nodes; i++)
            {
                adj_matrix[i] = new int[num_nodes];
                for(int j=0; j<num_nodes; j++)
                {
                    adj_matrix[i][j] = 0;
                }
            }
            for(int i=0; i<num_edges; i++)
            {
                int first, second;
                cin >> first >> second;
                adj_matrix[first][second] = 1;
                adj_matrix[second][first] = 1;
            }
        }
    	bool has_path(int si, int ei, bool *visited)
        {
            if(num_nodes == 0 || num_edges == 0)
            {
                return false;
            }
            if(adj_matrix[si][ei] == 1)
            {
                return true;
            }
            visited[si] = true;
            for(int i=0; i<num_nodes; i++)
            {
                if(i == si)
                {
                    continue;
                }
                else if(adj_matrix[si][i] == 1 && visited[i] == false)
                {
                    bool ans = has_path(i, ei, visited);
                    if(ans == true)
                    {
                        return true;
                    }
                }
            }
			return false;
        }
};
int main(void)
{
    int num_nodes, num_edges, si, ei;
    cin >> num_nodes >> num_edges;
    graph g1(num_nodes, num_edges);
    cin >> si >> ei;
    bool *visited = new bool[num_nodes];
    for(int i=0; i<num_nodes; i++)
    {
        visited[i] = false;
    }
    if(g1.has_path(si, ei, visited))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}