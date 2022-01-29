// Array Intersection
// Send Feedback
// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
// Note :
// Input arrays/lists can contain duplicate elements.

// The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).


// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

// The second line contains 'N' single space separated integers representing the elements of the first the array/list.

// The third line contains an integer 'M' representing the size of the second array/list.

// The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
// Output format :
// For each test case, print the intersection elements in a row, separated by a single space.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^6
// 0 <= M <= 10^6

// Time Limit: 1 sec 

#include <iostream>
#include <algorithm>
using namespace std;
void merge(int *arr, int size, int mid)
{
    int *tempArr = new int[size];
    int i=0, j=mid+1, k=0;
    
    while(i<=mid && j<size)
    {
        if(arr[i] < arr[j])
            tempArr[k++] = arr[i++];
        else if(arr[j] < arr[i])
            tempArr[k++] = arr[j++];
    	else
        {
            tempArr[k++] = arr[i++];
        	tempArr[k++] = arr[j++];    
        }    
    }
    while(i <= mid)
        tempArr[k++] = arr[i++];
    while(j < size)
        tempArr[k++] = arr[j++];
    
    for(i=0, k=0; i<size, k<size; i++,k++)
        arr[i] = tempArr[k];
    return;
}

void mergeSort(int *arr, int size)
{
    if(size == 1)
        return;
    
    int mid = 0;
    
    if(size%2 == 0)
        mid = size/2 - 1;
    else
        mid = size/2;
    
    mergeSort(arr, mid+1);
    mergeSort(arr+mid+1, size-mid-1);
    merge(arr, size, mid);
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
    if (n == 0|| m == 0)
        return;
    
   	int currentIndex = 0;
    mergeSort(arr1, n);
    mergeSort(arr2, m);
    
    for(int i=0; i<n; i++)
    {
        for(int j=currentIndex; j<m; j++)
        {
            if(arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                currentIndex = j+1;
                break;
            }
            else if(arr2[j] < arr1[i])
            {
                continue;
            }
            else
            {
                currentIndex = j;
                break;
            }
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}