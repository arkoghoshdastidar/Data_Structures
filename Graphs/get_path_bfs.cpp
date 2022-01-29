// Code : Get Path - BFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// Print the path from v1 to v2 in reverse order.
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class graph
{
    private:
    	int** adj_matrix;
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
            for(int i=0; i<num_nodes; i++)
            {
                for(int j=0; j<num_nodes; j++)
                {
                    cout << adj_matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    	vector<int> get_path_bfs(int si, int ei, bool* visited)
        {
            vector<int> answer;
            if(num_nodes == 0 || num_edges == 0)
            {
                return answer;
            }
            if(si == ei)
            {
                answer.push_back(si);
                return answer;
            }
            int flag = 0;
            queue<int> pending;
            unordered_map<int, int> child_to_parent;
            pending.push(si);
            visited[si] = true;
            while(!pending.empty())
            {
                int temp = pending.front();
                pending.pop();
                for(int i=0; i<num_nodes; i++)
                {
                    if(i == temp)
                    {
                        continue;
                    }
                    if(adj_matrix[temp][i] == 1 && visited[i] == false)
                    {
                        if(i == ei)
                        {
                            child_to_parent.insert({i, temp});
                            answer.push_back(i);
                            visited[i] = true;
                            flag = 1;
                            break;
                        }
                        pending.push(i);
                        visited[i] = true;
                        child_to_parent.insert({i, temp});
                    }
                }
                if(flag == 1)
                {
                    break;
                }
            }
            if(answer.size() == 0)
            {
                return answer;
            }
            int i=0;
            while(answer.at(i) != si)
            {
                answer.push_back(child_to_parent[answer.at(i)]);
                i++;
            }
            return answer;
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
    vector<int> answer = g1.get_path_bfs(si, ei, visited);
    for(int i=0; i<answer.size(); i++)
    {
        cout << answer.at(i) << " ";
    }
    cout << endl;
    return 0;
}