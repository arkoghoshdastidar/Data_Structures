#include<iostream>
using namespace std;

// Pass by value.
void swapv(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    return;
}
// Pass by address.
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
    return;
}
// Pass by reference.
void swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    return;
}

int main(void)
{
    int a,b;
    a=20;
    b=30;
    swapv(a,b);
    cout<<"Value of a,b after pass by value = "<<a<<" "<<b<<endl;
    swap(&a,&b);
    cout<<"Value of a,b after pass by address = "<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<"Value of a,b after pass by reference = "<<a<<" "<<b<<endl;
    return(0);
}