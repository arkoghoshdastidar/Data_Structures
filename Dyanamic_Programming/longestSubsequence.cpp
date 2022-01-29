// Longest Increasing Subsequence
// Send Feedback
// Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
// Input Format
// The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
// Output Format
// The first and only line of output contains the length of longest subsequence.
// Constraints
// 1 <= N <= 10^3
// Time Limit: 1 second
// Sample Input 1 :
// 6
// 5 4 11 1 16 8
// Sample Output 1 :
// 3
// Sample Output Explanation
// Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
// Sample Input 2 :
// 3
// 1 2 2
// Sample Output 2 :
// 2
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int clean(int *temp, int *arr, int n)
{
    int overlapping = 0;
    unordered_map<int, bool> data_count;
    priority_queue<int, vector<int>, greater<int>> bucket;
    for (int i = 0; i < n; i++)
    {
        if (data_count.count(arr[i]))
        {
            overlapping++;
        }
        else
        {
            bucket.push(arr[i]);
            data_count.insert({arr[i], true});
        }
    }
    for (int i = 0; i < n - overlapping; i++)
    {
        temp[i] = bucket.top();
        bucket.pop();
    }
    return n - overlapping;
}
int LIS_HELPER(int *arr, int *temp, int size1, int size2, int **output)
{
    if (size1 == 0 || size2 == 0)
    {
        return 0;
    }
    if (output[size1][size2] != -1)
    {
        return output[size1][size2];
    }
    if (arr[0] == temp[0])
    {
        return 1 + LIS_HELPER(arr + 1, temp + 1, size1 - 1, size2 - 1, output);
    }
    int val1 = LIS_HELPER(arr + 1, temp, size1 - 1, size2, output);
    int val2 = LIS_HELPER(arr, temp + 1, size1, size2 - 1, output);
    output[size1][size2] = max(val1, val2);
    return output[size1][size2];
}
int longestIncreasingSubsequence(int *arr, int n)
{
    int *temp = new int[n];
    int size2 = clean(temp, arr, n);
    int **output = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = new int[size2 + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < size2 + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    int answer = LIS_HELPER(arr, temp, n, size2, output);
    for (int i = 0; i < n + 1; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longestIncreasingSubsequence(arr, n);
}