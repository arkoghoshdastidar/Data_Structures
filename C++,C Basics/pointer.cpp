#include<iostream>
using namespace std;
/*
    Pointers are variables which stores the address of another variable.
*/
int main(void)
{
    int A[5]={1,2};
    int *arrPtr=A;
    do{
        cout<<*(arrPtr++)<<endl;
    }while(arrPtr!=A+5);
    return(0);
}