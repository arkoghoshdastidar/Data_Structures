#include <iostream>
using namespace std;

// This is a brute force approach to get nth fibonnaci number with time complexity of O(2^n)
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// This is called memoization in which we store the values once they are calculated so that we don't
// need to calculate it once again later. Memoization is a recursive top-down approach. This function has a time complexity of O(n).
int fib(int n, int *arr)
{
    if (n <= 1)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int a = fib(n - 1, arr);
    int b = fib(n - 2, arr);
    arr[n] = a + b;
    return arr[n];
}

int fib_better(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    delete arr;
    return fib(n, arr);
}

// The following method is called dyanamic programming. Dyanamic programming is an optimization of recursive method. It is same as memoization but in this case we follow bottom up approach instead of top down approach.

int fib_dp(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
int main(void)
{
    cout << fib_dp(100) << endl;
    return 0;
}