// Code : Pair Sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
// Input format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.
// Output format :
// The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
// Constraints :
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 2 1 -2 2 3
// Sample Output 1:
// 2
#include <iostream>
using namespace std;
#include <unordered_map>
int pairSum(int *arr, int size)
{
    unordered_map<int, int> values;
    for (int i = 0; i < size; i++)
    {
        if (values.count(arr[i]) > 0)
        {
            values.at(arr[i]) = values.at(arr[i]) + 1;
            continue;
        }
        values[arr[i]] = 1;
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            if (values.count(arr[i]) > 0)
            {
                if (values.at(arr[i]) >= 2)
                {
                    int zero = values.at(arr[i]);
                    count += zero * (zero - 1) / 2;
                }
                values.erase(arr[i]);
            }
        }
        if (values.count(-1 * arr[i]) > 0)
        {
            count += values.at(arr[i]) * values.at(-1 * arr[i]);
            values.erase(arr[i]);
            values.erase(-1 * arr[i]);
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}