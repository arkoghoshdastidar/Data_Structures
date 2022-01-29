// Coding Ninjas
// Send Feedback
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
// Input Format :
// The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix.
// Each of the following N lines contain M characters. Please note that characters are not space separated.
// Output Format :
// Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
// Constraints :
// 1 <= N <= 1000
// 1 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output 1:
// 1
#include <iostream>
#include <vector>
using namespace std;
bool hasPath(vector<vector<char>> &board, int n, int m, int i, int j, string str, bool **visited)
{
    if (str.size() == 0)
    {
        return true;
    }
    if (str.size() == 1 && board[i][j] == str.at(0))
    {
        return true;
    }
    if (str.at(0) != board[i][j])
    {
        return false;
    }
    bool ans = false;
    visited[i][j] = true;
    if (i - 1 >= 0 && j - 1 >= 0 && !visited[i - 1][j - 1])
    {
        ans = hasPath(board, n, m, i - 1, j - 1, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (i - 1 >= 0 && !visited[i - 1][j])
    {
        ans = hasPath(board, n, m, i - 1, j, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (i - 1 >= 0 && j + 1 < m && !visited[i - 1][j + 1])
    {
        ans = hasPath(board, n, m, i - 1, j + 1, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (j + 1 < m && !visited[i][j + 1])
    {
        ans = hasPath(board, n, m, i, j + 1, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (i + 1 < n && j + 1 < m && !visited[i + 1][j + 1])
    {
        ans = hasPath(board, n, m, i + 1, j + 1, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (i + 1 < n && !visited[i + 1][j])
    {
        ans = hasPath(board, n, m, i + 1, j, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (i + 1 < n && j - 1 >= 0 && !visited[i + 1][j - 1])
    {
        ans = hasPath(board, n, m, i + 1, j - 1, str.substr(1), visited);
        if (ans)
        {
            return ans;
        }
    }
    if (j - 1 >= 0 && !visited[i][j - 1])
    {
        ans = hasPath(board, n, m, i, j - 1, str.substr(1), visited);
    }
    visited[i][j] = false;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    string str = "CODINGNINJA";
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                visited[i][j] = true;
                ans = hasPath(board, n, m, i, j, str, visited);
            }
            if (ans)
            {
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);
}