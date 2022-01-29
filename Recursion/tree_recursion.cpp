#include<iostream>
using namespace std;

// When a function is called two or more than two times inside it's function block then it is called tree recursion.

void func(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        func(n-1);
        func(n-1);
    }
}

int main(void)
{
    func(3);
    return(0);
}