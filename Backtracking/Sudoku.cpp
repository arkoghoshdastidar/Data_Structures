// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.
// Sample Sudoku for you to get the logic for its solution:
// Example 1:
// Input:
// grid[][] = 
// [[3 0 6 5 0 8 4 0 0],
// [5 2 0 0 0 0 0 0 0],
// [0 8 7 0 0 0 0 3 1 ],
// [0 0 3 0 1 0 0 8 0],
// [9 0 0 8 6 3 0 0 5],
// [0 5 0 0 9 0 6 0 0],
// [1 3 0 0 0 0 2 5 0],
// [0 0 0 0 0 0 0 7 4],
// [0 0 5 2 0 6 3 0 0]]
// Output:
// 3 1 6 5 7 8 4 9 2
// 5 2 9 1 3 4 7 6 8
// 4 8 7 6 2 9 5 3 1
// 2 6 3 4 1 5 9 8 7
// 9 7 4 8 6 3 1 2 5
// 8 5 1 7 9 2 6 4 3
// 1 3 8 9 4 7 2 5 6
// 6 9 2 3 5 1 8 7 4
// 7 4 5 2 8 6 3 1 9
// Your Task:
// You need to complete the two functions:
// SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
// printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.
// Expected Time Complexity: O(9N*N).
// Expected Auxiliary Space: O(N*N).
#include <iostream>
using namespace std;
#define N 9
#define UNSIGNNED 0
class Solution
{
    bool checkVertical(int grid[N][N], int y, int data)
    {
        for (int i = 0; i < N; i++)
        {
            if (grid[i][y] == data)
            {
                return false;
            }
        }
        return true;
    }

    bool checkHorizontal(int grid[N][N], int x, int data)
    {
        for (int i = 0; i < N; i++)
        {
            if (grid[x][i] == data)
            {
                return false;
            }
        }
        return true;
    }

    bool checkBlock(int grid[N][N], int x, int y, int data)
    {
        int start_row = 0;
        int start_column = 0;
        if (x >= 0 && x < 3)
        {
            start_row = 0;
        }
        else if (x >= 3 && x < 6)
        {
            start_row = 3;
        }
        else
        {
            start_row = 6;
        }
        if (y >= 0 && y < 3)
        {
            start_column = 0;
        }
        else if (y >= 3 && y < 6)
        {
            start_column = 3;
        }
        else
        {
            start_column = 6;
        }
        for (int i = start_row; i < start_row + 3; i++)
        {
            for (int j = start_column; j < start_column + 3; j++)
            {
                if (grid[i][j] == data)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N], int x = 0, int y = 0)
    {
        if (x == 9)
        {
            return true;
        }
        if (grid[x][y] != 0)
        {
            if (y == 8)
            {
                return SolveSudoku(grid, x + 1, 0);
            }
            else
            {
                return SolveSudoku(grid, x, y + 1);
            }
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                if (checkVertical(grid, y, i) && checkHorizontal(grid, x, i) && checkBlock(grid, x, y, i))
                {
                    grid[x][y] = i;
                    bool smallAnswer;
                    if (y == 8)
                    {
                        smallAnswer = SolveSudoku(grid, x + 1, 0);
                    }
                    else
                    {
                        smallAnswer = SolveSudoku(grid, x, y + 1);
                    }
                    if (smallAnswer == true)
                    {
                        return true;
                    }
                    else
                    {
                        grid[x][y] = 0;
                        continue;
                    }
                }
            }
        }
        return false;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int grid[N][N];
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        if(ob.SolveSudoku(grid))
        {
            ob.printGrid(grid);
        }
        else
        {
            cout << "No solution exists!" << endl;
        }
    }
    return 0;
}