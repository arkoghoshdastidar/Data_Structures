// Code : Staircase using Dp
// Send Feedback
// A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
// Input format :
// The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
// Output format :
// Print the total possible number of ways.
//  Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec
// Sample Input 1:
// 4
// Sample Output 1:
// 7
// Sample Input 2:
// 10
// Sample Output 2:
// 274
#include <iostream>
using namespace std;
long staircase(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    long *arr = new long[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < n + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    long ans = arr[n];
    delete arr;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}