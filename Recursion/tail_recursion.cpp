#include<iostream>
#include<cstdio>
using namespace std;

void func(int n)
{
    // This is tail recursion.It this printing is done while ascending the stack frame.
    if(n>0)
    {
        printf("%d ",n);
        func(n-1);
    }
    if(n==0){
        printf("\n");
        return;
    }
}

int main(void)
{
    func(5);
    return(0);
}