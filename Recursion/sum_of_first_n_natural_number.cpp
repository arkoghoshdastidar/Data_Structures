#include<iostream>
using namespace std;

// sum(n)=sum(n-1)+n

// recursive method
int sum(int n)
{
    if(n>0)
        return(n+sum(n-1));
    else
        return(0);
}

// iterative method
int isum(int n)
{
    int retVal=0;
    for(int i=0;i<=n;i++)
        retVal+=i;
    return(retVal);
}

// formula method
int fsum(int n)
{
    return((n*(n+1))/2);
}
int main(void)
{
    cout<<sum(10)<<endl<<isum(10)<<endl<<fsum(10)<<endl;
    return(0);
}