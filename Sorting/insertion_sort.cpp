#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int key,i,j;
    for(i=1; i<size; i++)
    {
        key = arr[i];
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>key)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=key;
    }
}

int main(void)
{
    int arr[5] = {22,4,1,5,-9};
    insertion_sort(arr, 5);
    for(int x:arr)
        cout<<x<<" ";
    return(0);
}