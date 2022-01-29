#include<iostream>
#include<iomanip>
using namespace std;

/*
    Taylor series of e^x = 1 + x/1 + x^2/2! + x^3/3! + ...... + x^n/n!
*/

double e(int x, int n)
{
    static double tempVal = 1;
    if(n == 1)
        return(1*tempVal);
    else
    {
        tempVal = (tempVal*x/(n-1)) + 1;
        e(x,n-1);
        return(tempVal);
    }
}

int main(void)
{
    cout << "e^5 with precision of 10 = " << e(5,10) << endl;
    return(0);
}