#include<iostream>
using namespace std;

/*
    e(x,6) = 1 + x[1 + x/2[1 + x/3[1 + x/4[1 + x/5]]]]
*/

double e(int x, int n)
{
    double retVal = 1;
    for(int i=n-1;i>0;i--)
    {
        retVal = retVal*x/i;
        retVal++;
    }
    return(retVal);
}

int main(void)
{
    cout << "e(1,10) = " << e(1,10) << endl; 
    cout << "e(2,10) = " << e(2,10) << endl; 
    cout << "e(3,10) = " << e(3,10) << endl; 
    cout << "e(4,10) = " << e(4,10) << endl; 
    cout << "e(5,10) = " << e(5,10) << endl; 
    return(0);
}