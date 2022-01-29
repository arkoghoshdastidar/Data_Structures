#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
        return (0);
    int ans = sumOfDigits(n / 10);
    ans = ans + n % 10;
    return (ans);
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
}