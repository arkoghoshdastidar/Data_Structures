// N-Queen Problem
// Send Feedback
// You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Note: Don't print anything if there isn't any valid configuration.
// Input Format:
// The first line of input contains an integer, that denotes the value of N.
// Output Format :
// In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
// Constraints :
// 1 <= N <= 10
// Time Limit: 1 second
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
// Explanation:
// The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other.
#include <iostream>
using namespace std;

bool check(int **arr, int x, int y, int size)
{
    int leftDiagonal = y - 1;
    int rightDiagonal = y + 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (leftDiagonal >= 0)
        {
            if (arr[i][leftDiagonal] == 1)
                return false;
        }
        if (rightDiagonal < size)
        {
            if (arr[i][rightDiagonal] == 1)
                return false;
        }
        if (arr[i][y] == 1)
        {
            return false;
        }
        leftDiagonal--;
        rightDiagonal++;
    }
    return true;
}

void print(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

void NQueen(int **arr, int size, int row)
{
    if (row == size - 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (check(arr, row, i, size))
            {
                arr[row][i] = 1;
                print(arr, size);
                arr[row][i] = 0;
            }
        }
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (check(arr, row, i, size))
        {
            arr[row][i] = 1;
            NQueen(arr, size, row + 1);
            arr[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    NQueen(arr, n, 0);
    return 0;
}