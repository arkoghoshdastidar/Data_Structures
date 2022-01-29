#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size)
{
    int* min_num = 0;
    for(int i=0; i<size-1; i++)
    {
        min_num = &arr[i];
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] < *min_num)
                min_num = &arr[j];
        }
        swap(&arr[i],min_num);
    }
}

int main(void)
{
    int arr[5] = {2,1,-9,90,0};
    selection_sort(arr, 5);
    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;
    return(0);
}