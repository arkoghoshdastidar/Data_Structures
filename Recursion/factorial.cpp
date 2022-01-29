#include<iostream>
using namespace std;

// fact(n)=n*fact(n-1)
int fact(int n)
{
    if(n==0||n==1)
        return(1);
    else
        return(n*fact(n-1));
}
// iterative method
int iFact(int n)
{
    int retVal=1;
    for(int i=1;i<=n;i++)
        retVal*=i;
    return(retVal);
}
int main(void)
{
    int x;
    cin>>x;
    cout<<fact(x)<<endl<<iFact(x)<<endl;
    return(0);
}