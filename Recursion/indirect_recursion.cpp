#include<iostream>
using namespace std;
// Indirect recursion occurs when a function calls another function meanwhile the other function calls the first function after execution of the programs in the function block.
void funcB(int n);
void funcA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funcB(n-1);
    }
}
void funcB(int n)
{
    if(n>=0)
    {
        cout<<n<<" ";
        funcA(n/2);
    }
}
int main(void)
{
    funcA(20);
    return(0);
}