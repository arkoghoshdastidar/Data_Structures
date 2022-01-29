// Duplicate in array
// Send Feedback
// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
// Note :
// Duplicate number is always present in the given array/list.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.
// Output Format :
// For each test case, print the duplicate element in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^6

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 0 7 2 5 4 7 1 3 6

#include <iostream>
using namespace std;
void merge(int *arr,int size, int mid)
{
    int *tempArr = new int[size];
    int i=0, j=mid+1, k=0;
    while(i<=mid && j<size)
    {
        if(arr[i]<arr[j])
        {
            tempArr[k++]=arr[i++];
        }
        else if(arr[i]>arr[j])
        {
            tempArr[k++]=arr[j++];
        }
        else
        {
            tempArr[k++]=arr[i++];
            tempArr[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        tempArr[k++]=arr[i++];
    }
    while(j<size)
    {
        tempArr[k++]=arr[j++];
    }
    for(k=0,i=0; k<size,i<size; k++,i++)
		arr[i]=tempArr[k];
    return;
}
void mergeSort(int *arr, int size)
{
    if(size == 1)
        return;
    
    int mid = 0;
    if(size%2 == 0)
        mid = size/2-1;
    else
        mid = size/2;
    
    mergeSort(arr, mid+1);
    mergeSort(arr+mid+1, size-mid-1);
    merge(arr, size, mid);
}

int findDuplicate(int *arr, int size)
{
   mergeSort(arr, size);
   for(int i=0; i<size-1; i++)
   {
       if(arr[i] == arr[i+1])
           return arr[i];
   }
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}