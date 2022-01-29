#include<iostream>
using namespace std;
/*
    structure's are user defined data-types,which contain data elements of different data types.
*/
struct rectangle{
    double length;
    int breadth;
};

int main(void)
{
    cout<<"size of double = "<<sizeof(double)<<endl;
    cout<<"size of struct rectangle = "<<sizeof(rectangle)<<endl;
    rectangle r;
    r.length=10;
    r.breadth=15;
    cout<<"area of rectangle = "<<r.length*r.breadth<<endl;
    cout<<"size of r = "<<sizeof(r)<<endl;
    return(0);
}