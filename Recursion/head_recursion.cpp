#include<iostream>
using namespace std;

void func(int n)
{
    if(n>0)
    {
        func(n-1);
        cout<<n;
    }
    if(n==0)
    {
        cout<<endl;
        return;
    }
}

int main(void)
{
    int x;
    cin>>x;
    func(x);
    return(0);
}