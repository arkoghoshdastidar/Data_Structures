#include<iostream>
using namespace std;

int nCr(int n, int r)
{
    if(r == 0)
        return(1);
    return(n*nCr(n-1, r-1)/r);
}

int main(void)
{
    cout << "2C0 = " << nCr(2,0) << endl;
    cout << "5C2 = " << nCr(5,2) << endl;
    cout << "2C2 = " << nCr(2,2) << endl;
    cout << "6C3 = " << nCr(6,3) << endl;
    return(0);
}