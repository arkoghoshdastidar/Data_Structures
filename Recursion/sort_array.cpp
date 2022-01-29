#include<iostream>
using namespace std;

bool sort_array(int *arr, int n)
{
    if(n == 1)
        return(true);
    if(arr[0] > arr[1])
        return(false);
    return(sort_array(arr+1,n-1));
}

bool sort_array_2(int *arr, int n)
{
    if(n == 1)
        return(true);
    bool x = sort_array_2(arr+1,n-1);
    if(x){
        if(arr[0] < arr[1])
            return(true);
        else
        {
            return(false);
        }
        
    }
    else
    {
        return(false);
    }
    
}

int main(void)
{
    int arr[6] = {1,2,3,8,5,6};
    cout << sort_array(arr,6) << endl;
    cout << sort_array_2(arr,6) << endl;
    return(0);
}