#include<iostream>
using namespace std;

struct rectangle
{
    int length,breadth;
};

int main(void)
{
    rectangle r;
    rectangle* strPtr=&r;
    (*strPtr).length=10;
    strPtr->breadth=20;
    cout<<strPtr->length<<" "<<strPtr->breadth<<endl;
    // Initializing a pointer to a structure dynamically.
    rectangle *strPtr_2=new rectangle;
    strPtr_2->length=12;
    strPtr_2->breadth=15;
    cout<<strPtr_2->length<<" "<<strPtr_2->breadth<<endl;
    return(0);
}