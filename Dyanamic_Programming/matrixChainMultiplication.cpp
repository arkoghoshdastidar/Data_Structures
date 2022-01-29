#include <iostream>
using namespace std;
// Brute-Force solution
#include <climits>
int matrixChainMultiplication(int *arr, int si, int ei)
{
    if (ei - si <= 1)
    {
        return 0;
    }
    int finalAns = INT_MAX;
    for (int k = si + 1; k < ei; k++)
    {
        int temp = matrixChainMultiplication(arr, si, k) + matrixChainMultiplication(arr, k, ei) + arr[si] * arr[k] * arr[ei];
        finalAns = min(finalAns, temp);
    }
    return finalAns;
}
int matrixChainMultiplication(int *arr, int n)
{
    return matrixChainMultiplication(arr, 0, n);
}
// Memoization
#include <climits>
int matrixChainMultiplication(int *arr, int si, int ei, int **output)
{
    if (ei - si <= 1)
    {
        return 0;
    }
    if (output[si][ei] != -1)
    {
        return output[si][ei];
    }
    int finalAns = INT_MAX;
    for (int k = si + 1; k < ei; k++)
    {
        int temp = matrixChainMultiplication(arr, si, k, output) + matrixChainMultiplication(arr, k, ei, output) + arr[si] * arr[k] * arr[ei];
        finalAns = min(finalAns, temp);
    }
    output[si][ei] = finalAns;
    return finalAns;
}

int matrixChainMultiplication(int *arr, int n)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            output[i][j] = -1;
    }
    return matrixChainMultiplication(arr, 0, n, output);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}