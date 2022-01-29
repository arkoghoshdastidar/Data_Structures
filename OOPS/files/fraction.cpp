#include<iostream>
#include"fractionClass.cpp"
using namespace std;

int main(void)
{
    fraction f1(10, 2);
    fraction f2(15, 4);
    f1.add(f2);
    f1.print();
    f2.print();

    fraction f3(12, 5);
    fraction f4(13,2);
    f3.multiply(f4);
    f3.print();
    f4.print();
    return(0);
}