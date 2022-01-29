#include<iostream>
#include<cstdio>
using namespace std;

int x=0;

int func(int n)
{
    if(n>0)
    {
        x++;
        return(func(n-1)+x);
    }
    else    
        return(0);
}

int main(void)
{
    int x;
    cin>>x;
    x=func(x);
    return(0);
}