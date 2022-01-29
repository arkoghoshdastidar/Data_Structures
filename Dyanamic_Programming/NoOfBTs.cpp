// Code : No. of balanced BTs
// Send Feedback
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so, return output modulus 10^9 + 7.
// Write a simple recursive solution.
// Input Format :
// The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
// Output Format :
// The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
// Constraints :
// 1 <= h <= 24
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315
#include <iostream>
using namespace std;
// BruteForceApproach
long balancedBTs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 3;
    }
    long n_1 = balancedBTs(n - 1) % 1000000007;
    long n_2 = balancedBTs(n - 2) % 1000000007;
    long solution = n_1 * n_1 + 2 * (n_1 * n_2);
    return solution % 1000000007;
}
// DyanamicProgramming
long balancedBT_DP(int n)
{
    long *data = new long[n + 1];
    data[0] = 1;
    data[1] = 1;
    data[2] = 3;
    for (int i = 3; i < n + 1; i++)
    {
        data[i] = (((data[i - 1]) * (data[i - 1])) % 1000000007 + 2 * ((data[i - 1]) * (data[i - 2])) % 1000000007) % 1000000007;
    }
    long ans = data[n];
    delete data;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}