#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int minCount(int n, int *arr)
{
    if (n == 0)
    {
        return 0;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int sq = sqrt(n);
    int count = INT_MAX;
    for (int i = 1; i <= sq; i++)
    {
        int smallAns = minCount(n - i * i, arr);
        if (smallAns < count)
        {
            count = smallAns;
        }
    }
    arr[n] = count + 1;
    return arr[n];
}
int minCount(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return minCount(n, arr);
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}