#include<iostream>
using namespace std;
/*
    Modular programming is a programming method in which we create functions to accomplish
    certain tasks.A function can be used more than on time.It is better than monolithic
    programming.
*/
int area(int l,int b){
    return(l*b);
}
int perimeter(int l,int b){
    return(2*(l+b));
}
int main(void)
{
    int length=0,breadth=0;
    cin>>length>>breadth;
    cout<<"Area = "<<area(length,breadth)<<endl<<"Perimeter = "<<perimeter(length,breadth)<<endl;
    return(0);
}