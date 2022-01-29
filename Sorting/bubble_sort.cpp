#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble_sort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(void)
{
    int arr[5] = {22,3,19,-8,-9};
    bubble_sort(arr, 5);
    for(int x:arr)
        cout<<x<<" ";
    return(0);
}