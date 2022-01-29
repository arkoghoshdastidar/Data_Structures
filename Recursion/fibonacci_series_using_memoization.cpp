#include<iostream>
using namespace std;

// memoization is a method to store the values of a function call into a global/static array for     future reference.

int fib_array[10];

int fib(int n)
{
    if(n <= 1)
        return(fib_array[n]);
    else
    {
        if(fib_array[n-1] == -1)
            fib_array[n-1] = fib(n-1);
        if(fib_array[n-2] == -2)
            fib_array[n-2] = fib(n-2);
        fib_array[n] = fib_array[n-1] + fib_array[n-2];
        return(fib_array[n]);
    }
    
}

int main(void)
{
    for(int i = 0; i < 100; i++)
        fib_array[i] = -1;
    fib_array[0] = 0;
    fib_array[1] = 1;

    cout << "fib(0) = " << fib(0) << endl;
    cout << "fib(1) = " << fib(1) << endl;
    cout << "fib(2) = " << fib(2) << endl;
    cout << "fib(3) = " << fib(3) << endl;
    cout << "fib(4) = " << fib(4) << endl;
    cout << "fib(5) = " << fib(5) << endl;

    return(0);
}