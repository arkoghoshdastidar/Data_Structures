#include<iostream>
using namespace std;

// Nested recursion involves calling of a function inside another function call.
int func(int n)
{
    if(n>100)
        return(n-10);
    else
        return(func(func(n+11)));
} 

int main(void)
{
    int r=func(12);
    cout<<r<<endl;
    r=func(91);
    cout<<r<<endl;
    r=func(120);
    cout<<r<<endl;
    return(0);
}