#include<iostream>
using namespace std;
/*
    Monolithic programming is a programming method in which the main function contains the complete program,it is a bad programming practice.
*/
int main(void)
{
    int length=0,breadth=0;
    cin>>length>>breadth;
    int area=length*breadth;
    int perimeter=2*(length+breadth);
    cout<<"Area = "<<area<<endl<<"Perimeter = "<<perimeter<<endl;
    return(0);
}