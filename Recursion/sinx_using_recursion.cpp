#include<iostream>
using namespace std;

// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...... + ((-1)^(n+1))(x^(2n-1))/(2n-1)!

double sin(double x, int n)
{
    static double nr = x;
    static double f = 1;
    if(n == 1)
        return(x);
    else
    {
        double tempVal = sin(x, n-1);
        nr = nr*x*x;
        f = f*(2*n-1)*(2*n-2);
        if(n%2 == 0)
            tempVal = tempVal - nr/f;
        else 
            tempVal = tempVal + nr/f;
        return(tempVal);
    }
}

int main(void)
{
    cout << "sin(2.004, 5) = " << sin(2.004, 5) << endl;
    return(0);
}