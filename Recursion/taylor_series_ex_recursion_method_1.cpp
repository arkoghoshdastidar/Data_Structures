#include<iostream>
using namespace std;

/*
    Taylor series of e^x = 1 + x/1 + x^2/2! + x^3/3! + ...... + x^n/n!
*/

double e(int x, int n)
{
    static double p = 1;
    static double f = 1;
    double tempVal = 0;
    if(n == 0)
        return(1);
    else
    {
        tempVal = e(x, n-1);
        p = p*x;
        f = f*n;
        return(tempVal + p/f);   
    }
}

int main(void)
{
    cout << "e^5 = " << e(5,100) << endl;
    return(0);
}