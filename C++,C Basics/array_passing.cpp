#include<iostream>
using namespace std;
// Creating array dynamically into the heap.
int * create_array(int n){
    int *temp_arr=new int[n];
    return(temp_arr);
}
// Passing array into print function.
// NOTE:- An array can only be passed by address into a function.
void print_array(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return;
}
void insert_value(int *arr,int n){
    for(int i=0;i<n;i++)
        arr[i]=i;
    return;
}
int main(void)
{
    int *arr=create_array(5);
    insert_value(arr,5);
    print_array(arr,5);
    return(0);
}