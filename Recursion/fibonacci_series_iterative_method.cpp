#include<iostream>
using namespace std;

int fibonacci(int n)
{
    int t0 = 0, t1 = 1, s;
    if(n<=1)
        return(n);
    for(int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return(s);
}

int main(void)
{
    cout << "fibonacci(3) = " << fibonacci(3) << endl;
    cout << "fibonacci(5) = " << fibonacci(5) << endl;
    cout << "fibonacci(7) = " << fibonacci(7) << endl;
    return(0);
}