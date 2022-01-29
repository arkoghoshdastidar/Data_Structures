// Pairs with difference K
// Send Feedback
// You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
// Note: Take absolute difference between the elements of the array.
// Input Format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
// The following line contains n space separated integers, that denote the value of the elements of the array.
// The following line contains an integer, that denotes the value of K.
// Output format :
// The first and only line of output contains count of all such pairs which have an absolute difference of K.
// Constraints :
// 0 <= n <= 10^4
// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 5 1 2 4
// 3
// Sample Output 1 :
// 2
// Sample Input 2 :
// 4
// 4 4 4 4
// 0
// Sample Output 2 :
// 6
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
int getPairsWithDifferenceK(int *arr, int size, int k)
{
    int count = 0;
    unordered_map<int, int> record;
    for (int i = 0; i < size; i++)
    {
        if (record.count(arr[i]) > 0)
        {
            record.at(arr[i]) += 1;
            continue;
        }
        record.insert({arr[i], 1});
    }
    for (int i = 0; i < size; i++)
    {
        if (record.count(arr[i]) > 0)
        {
            if (k == 0)
            {
                count += record.at(arr[i]) * (record.at(arr[i]) - 1) / 2;
                record.erase(arr[i]);
                continue;
            }
            int difference1 = arr[i] - k;
            if (record.count(difference1) > 0)
            {
                count += record.at(arr[i]) * record.at(difference1);
            }
            int difference2 = arr[i] + k;
            if (record.count(difference2) > 0)
            {
                count += record.at(arr[i]) * record.at(difference2);
            }
            record.erase(arr[i]);
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}