/*
What is a K-sorted array?
A K-sorted array is an array in which the element present at the i-th index will shift at most
K-1 positions to the left or K-1 positions to the right.

For-example:
10 12 15 6 9 -----> Before sorting
15 12 10 9 6 ----->After sorting
In the above example it can be clearly seen that all the elements are shifted at most 2 positions
to the left or right. Hence the array 10 12 15 6 9 is a 3-sorted array.
*/

#include <iostream>
#include <queue>
using namespace std;

void KSort(int *arr, int size, int K)
{
    priority_queue<int> pq;
    for(int i=0; i<size; i++)
    {
        if(i==0)
        {
            for(int i=0; i<K; i++)
            {
                pq.push(arr[i]);
            }
            arr[i] = pq.top();
            pq.pop();
        }
        else if(K+i-1 < size)
        {
            pq.push(arr[K+i-1]);
            arr[i] = pq.top();
            pq.pop();
        }
        else
        {
            arr[i] = pq.top();
            pq.pop();
        }
    }
}

int main(void)
{
    int arr[5] = {10, 12, 15, 6, 9};
    KSort(arr, 5, 3);
    for(int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}