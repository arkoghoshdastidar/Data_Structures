#include<iostream>
using namespace std;
int main(void)
{
    /*
        Arrays are inbuilt data types in Cplusplus,which stores data element of same data type
        in contigous memory locations in the main memory.
    */
    int A[5]={1,2,3,4,5};
    /*
        foreach loop syntax in Cplusplus

        1.
            for(data_type variable_name : array_name){
                main code 
            }
        2.
           after each iteration the variable_name is automatically incremented and points to the next array elment.
    */
    for(int x:A)
        cout<<x<<endl;
    return(0);
}