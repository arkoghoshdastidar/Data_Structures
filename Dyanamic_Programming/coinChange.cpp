// Ways To Make Coin Change
// Send Feedback
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
// Return 0 if the change isn't possible.
// Input Format
// The first line of the input contains an integer value N, which denotes the total number of denominations.

// The second line of input contains N values, separated by a single space. These values denote the value of denomination.

// The third line of the input contains an integer value, that denotes the value of V.
// Output Format
// Print the total total number of ways i.e. W.
// Constraints :
// 1 <= n <= 10
// 1 <= V <= 1000

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output 1 :
// 4
// Explanation to Sample Input 1 :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// 250
// Sample Output 2 :
// 13868903

#include <iostream>
using namespace std;
//Brute-Force Method
int countWaysToMakeChange(int coins[], int count, int value)
{
	if(value == 0)
    {
        return 1;
    }
    int ans = 0;
    for(int i=0; i<count; i++)
    {
        if(coins[i] <= value)
        {
            ans += countWaysToMakeChange(coins+i, count-i, value-coins[i]);
        }
    }
    return ans;
}
//Memoization
int helper(int coins[], int count, int value, int** output)
{
    if(value == 0)
    {
        return 1;
    }
    if(output[value][count] != -1)
    {
        return output[value][count];
    }
    int ans = 0;
    for(int i=0; i<count; i++)
    {
        if(coins[i] <= value)
        {
            ans += helper(coins+i, count-i, value-coins[i], output);
        }
    }
    output[value][count] = ans;
    return ans;
}

int countWaysToMakeChange_mem(int denominations[], int numDenominations, int value)
{
	int m = value + 1;
    int n = numDenominations+1;
    int** output = new int*[m];
    for(int i=0; i<m; i++)
    {
        output[i] = new int[n];
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            output[i][j] = -1;
        }
    }
    return helper(denominations, numDenominations, value, output);
}


int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}