#include <iostream>
#include <climits>
using namespace std;

// Brute-force approach
int countMinStepsToOne(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int a = countMinStepsToOne(n - 1);
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
    {
        b = countMinStepsToOne(n / 2);
    }
    if (n % 3 == 0)
    {
        c = countMinStepsToOne(n / 3);
    }
    return (1 + min(a, min(b, c)));
}

// Using memoization/dyanamic programming
int countStepsToOne(int n, int *arr)
{
    if (n == 1)
    {
        return 0;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    a = countStepsToOne(n - 1, arr);
    if (n % 2 == 0)
    {
        b = countStepsToOne(n / 2, arr);
    }
    if (n % 3 == 0)
    {
        c = countStepsToOne(n / 3, arr);
    }
    arr[n] = 1 + min(a, min(b, c));
    return arr[n];
}
int countStepsToOne(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    int ans = countStepsToOne(n, arr);
    delete arr;
    return ans;
}

// Solving minstepscounttoone using dynamic programming.
int countStepsToOne_dp(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else if (n == 3)
        return 1;
    int *arr = new int[n + 1];
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i < n + 1; i++)
    {
        int a, b = INT_MAX, c = INT_MAX;
        a = arr[i - 1];
        if (i % 2 == 0)
            b = arr[n / 2];
        if (i % 3 == 0)
            c = arr[n / 3];
        arr[i] = 1 + min(a, min(b, c));
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne_dp(n);
}