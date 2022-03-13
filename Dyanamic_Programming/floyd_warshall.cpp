#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    void shortest_distance_helper(vector<vector<int>> &matrix, int k)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if(i == k)
            {
                continue;
            }
            for (int j = 0; j < matrix.at(i).size(); j++)
            {
                if(j == k || i == j)
                {
                    continue;
                }
                if(matrix[i][k] != -1 && matrix[k][j] != -1)
                {
                    if(matrix[i][j] != -1)
                    {
                        matrix[i][j] = min(matrix[i][k]+matrix[k][j], matrix[i][j]);
                    }
                    else
                    {
                        matrix[i][j] = matrix[i][k]+matrix[k][j];
                    }
                }
            }
        }
    }

    void shortest_distance(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            shortest_distance_helper(matrix, i);
        }
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    obj.shortest_distance(matrix);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// 4
// 0 3 -1 7
// 8 0 2 -1
// 5 -1 0 1
// 2 -1 -1 0


// 12
// 0 4 2 1 2 9 4 8 -1 4 -1 -1
// 9 0 3 6 2 6 2 3 6 -1 -1 3
// 7 1 0 10 8 9 1 3 -1 7 -1 10
// 5 1 9 0 3 -1 1 10 7 1 -1 7
// -1 5 1 4 0 2 10 4 10 6 4 5
// 7 8 3 7 5 0 5 1 3 5 7 2
// 6 -1 6 1 10 7 0 10 -1 -1 7 7
// -1 3 2 7 4 -1 4 0 10 5 6 10
// 10 6 1 10 4 4 7 10 0 4 7 4
// 1 1 6 8 8 9 2 10 6 0 -1 3
// 5 9 3 -1 4 3 -1 -1 -1 3 0 1
// 2 2 8 6 2 4 4 3 -1 3 4 0