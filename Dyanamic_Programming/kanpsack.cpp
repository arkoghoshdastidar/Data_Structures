// Code : Knapsack
// Send Feedback
// A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
// Input Format :
// The first line of the input contains an integer value N, which denotes the total number of items.

// The second line of input contains the N number of weights separated by a single space.

// The third line of input contains the N number of values separated by a single space.

// The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
// Output Format :
// Print the maximum value of V that the thief can steal.
// Constraints :
// 1 <= N <= 20
// 1<= Wi <= 100
// 1 <= Vi <= 100

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13
// Sample Input 2 :
// 5
// 12 7 11 8 9
// 24 13 23 15 16
// 26
// Sample Output 2 :
// 51
#include <iostream>
#include <climits>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight, int sackWeight = 0, int sackValue = 0, int index = 0)
{
    if (index == n)
    {
        return sackValue;
    }
    int value1 = INT_MIN;
    if (sackWeight + weights[index] <= maxWeight)
    {
        value1 = knapsack(weights, values, n, maxWeight, sackWeight + weights[index], sackValue + values[index], index + 1);
    }
    int value2 = knapsack(weights, values, n, maxWeight, sackWeight, sackValue, index + 1);
    return max(value1, value2);
}
// Memoization
int ks_helper(int *weight, int *values, int n, int maxWeight, int index, int **output)
{
    if (index == n || maxWeight == 0)
    {
        return 0;
    }
    if (output[maxWeight][index] != -1)
    {
        return output[maxWeight][index];
    }
    int value1 = INT_MIN;
    int value2 = INT_MIN;
    if (weight[index] <= maxWeight)
    {
        value1 = values[index] + ks_helper(weight, values, n, maxWeight - weight[index], index + 1, output);
    }
    value2 = ks_helper(weight, values, n, maxWeight, index + 1, output);
    output[maxWeight][index] = (value1 > value2) ? value1 : value2;
    return output[maxWeight][index];
}
int ks_dp(int *weight, int *values, int n, int maxWeight)
{
    int **output = new int *[maxWeight + 1];
    for (int i = 0; i <= maxWeight; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= maxWeight; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    int answer = ks_helper(weight, values, n, maxWeight, 0, output);
    for (int i = 0; i <= maxWeight; i++)
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
    int *weights = new int[n];
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int maxWeight;
    cin >> maxWeight;
    cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << ks_dp(weights, values, n, maxWeight) << endl;
    delete[] weights;
    delete[] values;
}