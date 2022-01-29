#include<iostream>
using namespace std;
/*
    We can find the power of a number using pow (m,n) function.
    m ^ n = m * (m ^ (n-1))
    pow (m,n) = m * pow (m,n-1) 
*/

double pow (double m,int n)
{
    if(n == 0)
        return(1);
    return(m * pow (m,n-1));
}

int main(void)
{
    cout << "2 ^ 10 = " << pow(2,10) << endl;
    cout << "3 ^ 10 = " << pow(3,10) << endl;
    cout << "5 ^ 10 = " << pow(5,10) << endl;
    return(0);
}