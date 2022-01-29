#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 0||n == 1)
        return(n);
    else
    {
        return(n*fact(n-1));
    }
    
}

int main(void)
{
    cout << fact(4) << endl;
    cout << fact(5) << endl;
    cout << fact(10) << endl;
    return(0);
}