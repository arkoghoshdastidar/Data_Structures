#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 0 || n == 1)
        return(1);
    return( n*fact(n-1) );
}

int nCr(int n, int r)
{
    return((fact(n))/((fact(r))*(fact(n-r))));
}

int main(void)
{
    cout << "2C0 = " << nCr(2,0) << endl;
    cout << "5C2 = " << nCr(5,2) << endl;
    cout << "2C2 = " << nCr(2,2) << endl;
    cout << "6C3 = " << nCr(6,3) << endl;
    return(0);
}