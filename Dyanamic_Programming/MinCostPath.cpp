// Code : Min Cost Path
// Send Feedback
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i, j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.
//  Input format :
// The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// The second line onwards, the next 'M' lines or rows represent the ith row values.

// Each of the ith row constitutes 'N' column values separated by a single space.
// Output format :
// Print the minimum cost to reach the destination.
// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec
// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1
// Sample Output 1 :
// 13
// Sample Input 2 :
// 3 4
// 10 6 9 0
// -23 8 9 90
// -200 0 89 200
// Sample Output 2 :
// 76
// Sample Input 3 :
// 5 6
// 9 6 0 12 90 1
// 2 7 8 5 78 6
// 1 6 0 5 10 -4
// 9 6 2 -10 7 4
// 10 -2 0 5 5 7
// Sample Output 3 :
// 18
#include <iostream>
#include <climits>
using namespace std;
// Memoization
int minCostPath(int **input, int **output, int n, int m, int x = 0, int y = 0)
{
    if (x == n - 1 && y == m - 1)
    {
        output[x][y] = input[x][y];
        return input[x][y];
    }
    if (output[x][y] != INT_MAX)
    {
        return output[x][y];
    }
    int right = INT_MAX, down = INT_MAX, diagonal = INT_MAX;
    if (y + 1 < m)
    {
        right = minCostPath(input, output, n, m, x, y + 1);
    }
    if (x + 1 < n)
    {
        down = minCostPath(input, output, n, m, x + 1, y);
    }
    if (x + 1 < n && y + 1 < m)
    {
        diagonal = minCostPath(input, output, n, m, x + 1, y + 1);
    }
    output[x][y] = input[x][y] + min(right, min(down, diagonal));
    return output[x][y];
}

int minCostPath(int **input, int n, int m)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            output[i][j] = INT_MAX;
        }
    }
    int ans = minCostPath(input, output, n, m);
    for (int i = 0; i < n; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return ans;
}
// Tabulation
int MinCostPathDP(int **input, int n, int m)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[m];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i + 1 < n && j + 1 < m)
            {
                output[i][j] = input[i][j] + min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1]));
            }
            else if (i + 1 < n)
            {
                output[i][j] = input[i][j] + output[i + 1][j];
            }
            else if (j + 1 < m)
            {
                output[i][j] = input[i][j] + output[i][j + 1];
            }
            else
            {
                output[i][j] = input[i][j];
            }
        }
    }
    int answer = output[0][0];
    for (int i = 0; i < n; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}

int main(void)
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << MinCostPathDP(arr, n, m) << endl;
    return 0;
}