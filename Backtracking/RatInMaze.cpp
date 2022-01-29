// Rat In A Maze Problem
// Send Feedback
// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
// You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
// Input Format
// The first line of input contains an integer, that denotes the value of N.
// Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements.
// Output Format :
// Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.
// Constraints
// 1 <= N <= 18
// 0 <= Number of cells with value 1 <= 15
// Time Limit: 1 second
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1
// Explanation :
// Only 1 path is possible. The path is shown in the image below.
// Alt Text

// Sample Input 2 :
// 3
// 1 0 1
// 1 1 1
// 1 1 1
// Sample Output 2 :
// 1 0 0 1 1 1 1 1 1
// 1 0 0 1 0 0 1 1 1
// 1 0 0 1 1 0 0 1 1
// 1 0 0 1 1 1 0 0 1
// Explanation:
//  As described in the Sample Output 2, four paths are possible.
/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

void maze_runner(int **maze, int **path, int size, int x, int y)
{
    // Base case for printing the path array.
    if (x == size - 1 && y == size - 1)
    {
        path[x][y] = 1;
        print(path, size);
        path[x][y] = 0;
        return;
    }
    path[x][y] = 1;
    // Top
    if (x - 1 >= 0)
    {
        if (maze[x - 1][y] && !path[x - 1][y])
        {
            maze_runner(maze, path, size, x - 1, y);
        }
    }
    // Down
    if (x + 1 < size)
    {
        if (maze[x + 1][y] && !path[x + 1][y])
        {
            maze_runner(maze, path, size, x + 1, y);
        }
    }
    // Left
    if (y - 1 >= 0)
    {
        if (maze[x][y - 1] && !path[x][y - 1])
        {
            maze_runner(maze, path, size, x, y - 1);
        }
    }
    // Right
    if (y + 1 < size)
    {
        if (maze[x][y + 1] && !path[x][y + 1])
        {
            maze_runner(maze, path, size, x, y + 1);
        }
    }
    path[x][y] = 0;
}

int main()
{
    int n;
    cin >> n;
    int **maze = new int *[n];
    int **path = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        path[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            path[i][j] = 0;
        }
    }
    maze_runner(maze, path, n, 0, 0);
    return 0;
}