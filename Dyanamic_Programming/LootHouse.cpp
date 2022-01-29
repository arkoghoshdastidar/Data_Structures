// Loot Houses
// Send Feedback
// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input format :
// The first line of input contains an integer value of 'n'. It is the total number of houses.
// The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
// Output format :
// Print the the maximum money that can be looted.
// Constraints :
// 0 <= n <= 10 ^ 4
// Time Limit: 1 sec
// Sample Input 1 :
// 6
// 5 5 10 100 10 5
// Sample Output 1 :
// 110
// Sample Input 2 :
// 6
// 10 2 30 20 3 50
// Sample Output 2 :
// 90
// Explanation of Sample Output 2 :
// Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
#include <iostream>
using namespace std;
// Brute_Force
int maxMoneyLooted(int *arr, int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int lootHouse = maxMoneyLooted(arr + 2, n - 2);
    int dontLootHouse = maxMoneyLooted(arr + 1, n - 1);
    int answer = 0;
    if (lootHouse + arr[0] > dontLootHouse)
    {
        answer = lootHouse + arr[0];
    }
    else
    {
        answer = dontLootHouse;
    }
    return answer;
}
// Memoization
int maxLoot(int *arr, int n, int *output)
{
    if (n <= 0)
    {
        return 0;
    }
    if(output[n] != -1)
    {
        return output[n];
    }
    int loot = arr[0] + maxLoot(arr+2, n-2, output);
    int skip = maxLoot(arr+1, n-1, output);
    int ans;
    if(loot > skip){
        ans = loot;
    }else{
        ans = skip;
    }
    output[n] = ans;
    return ans;
}
int maxLoot(int *arr, int n)
{
    int *output = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = -1;
    }
    int answer = maxLoot(arr, n, output);
    delete output;
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
    cout << maxLoot(arr, n);
    delete[] arr;
}