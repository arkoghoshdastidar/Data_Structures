#include<iostream>
using namespace std;

/*
    The function present below is more efficient than the function present in power_1.cpp
    in terms of time and space complexity.
*/

double pow(double m, int n)
{
    if(n == 0)
        return(1);
    else
    {
        if(n % 2 == 0)
            return(pow (m * m, n / 2));
        else if(n % 2 != 0)
            return(m * pow (m * m, n / 2));
    }
    return(0);
}

int main(void)
{
    cout << "3 ^ 10 = " << pow (3, 10) << endl;
    cout << "4 ^ 10 = " << pow (4, 10) << endl;
    cout << "5 ^ 10 = " << pow (5, 10) << endl;
    return(0);
}