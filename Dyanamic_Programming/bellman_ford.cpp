#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        int source;
        int destination;
        int edgeLength;
        int *value = new int[n];
        for (int i = 0; i < n; i++)
        {
            value[i] = INT_MAX;
        }
        value[0] = 0;
        int count = 0;
        while (count < n - 1)
        {
            for (int i = 0; i < edges.size(); i++)
            {
                source = edges[i][0];
                destination = edges[i][1];
                edgeLength = edges[i][2];
                if (value[source] != INT_MAX && (value[destination] > value[source] + edgeLength))
                {
                    value[destination] = value[source] + edgeLength;
                }
            }
            count++;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            source = edges[i][0];
            destination = edges[i][1];
            edgeLength = edges[i][2];
            if (value[source] != INT_MAX && (value[destination] > value[source] + edgeLength))
            {
                return 1;
            }
        }
        return 0;
    }
};

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    Solution obj;
    cout << obj.isNegativeWeightCycle(n, edges) << endl;
    return 0;
}
// 7 25
// 0 1 2
// 0 2 -2
// 0 3 -1
// 0 4 -6
// 0 6 2
// 1 0 -2
// 1 2 4
// 1 4 -7
// 1 6 10
// 2 0 -8
// 2 1 10
// 2 6 -8
// 3 1 -1
// 3 4 4
// 4 1 -11
// 4 2 -10
// 4 3 -4
// 5 0 1
// 5 2 8
// 5 3 -3
// 5 4 3
// 5 6 6
// 6 0 9
// 6 1 1
// 6 3 -11