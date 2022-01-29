#include<iostream>
using namespace std;

//          1      2       3        4      ......                    n
// cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...... + ((-1)^(n+1))(x^(2*(n-1))/(2*(n-1))!)

double cos(double x, int n)
{
    static double nr = 1, f = 1;
    double retVal = 1;
    if(n == 1) 
        return(1);
    else
    {
        retVal = cos(x, n-1);
        nr = nr*x*x;
        f = f*(2*(n-1))*(2*(n-1)-1);
        if(n%2 == 0)
            retVal = retVal - (nr/f);
        else if(n%2 != 0)
            retVal = retVal + (nr/f);
        return(retVal);
    }
    
}

int main(void)
{
    cout << "cos(2.041, 10) = " << cos(2.041, 10) << endl;
    return(0);
}