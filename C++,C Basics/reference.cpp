#include<iostream>
using namespace std;

/*
    Reference variables are alias of original variable names.
    They must be initialized during declaration.
    They have the same address as that of the actual variable.
*/

int main(void)
{
    int a=0;
    int &ra=a;
    cout<<"a = "<<a<<endl<<"ra = "<<ra<<endl;
    cout<<"address of variable a = "<<&a<<endl<<"address of variable ra = "<<&ra<<endl;
    return(0);
}