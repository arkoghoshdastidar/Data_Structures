#include<iostream>
#include<cstdio>
using namespace std;

int func(int n)
{
    static int x=0;
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
    cout<<x<<endl;
    return(0);
}