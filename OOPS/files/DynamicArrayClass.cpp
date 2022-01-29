#include<iostream>
#include"DynamicArray.cpp"
using namespace std;

int main(void)
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.add(70);
    d1.add(80);
    d1.print();
    DynamicArray d2(d1);
    d2.add(0, 100);
    d2.add(7, 800);
    d2.print();
    DynamicArray d3;
    d3 = d2;
    d3.print();
    return(0);
}