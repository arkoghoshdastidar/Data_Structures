#include <iostream>
using namespace std;
int countZeros(int n)
{
    // Write your code here
    static int s = 0;
    if (s == 0 && n == 0)
        return (1);
    if (n == 0)
        return (0);
    s++;
    int ans = countZeros(n / 10);
    if (n % 10 == 0)
        ans += 1;
    return (ans);
}
int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}