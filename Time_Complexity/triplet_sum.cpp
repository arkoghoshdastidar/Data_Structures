// You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'X'.
// Output format :
// For each test case, print the total number of triplets present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= X <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7 
// 12
// Sample Output 1:
// 5

#include<iostream>
using namespace std;

void merge(int a[], int si, int ei)
{
	int size = ei - si + 1;
    int mid = (si + ei)/2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    int tempArr[size];
    
    while(i <= mid && j <=ei)
    {
        if(a[i] < a[j])
        {
            tempArr[k] = a[i];
            k++;
            i++;
        }
        else if(a[j] < a[i])
        {
            tempArr[k] = a[j];
            k++;
            j++;
        }
        else
        {
            tempArr[k] = a[i];
            k++;
            i++;
            tempArr[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        tempArr[k] = a[i];
        k++;
        i++;
    }
    while(j <= ei)
    {
        tempArr[k] = a[j];
        k++;
        j++;
    }
    
    i = si;
    k = 0;
    for(;i <= ei;)
    {
        a[i] = tempArr[k];
        i++;
        k++;
    }
}

void mergeSort(int input[], int size, int si = -1, int ei = -1)
{
    if(si == -1 && ei == -1)    
    {
        if(size == 0|| size == 1)
            return;
        si = 0;
        ei = size - 1;
    }
    
    if(si >= ei)
        return;
    
 	int mid = (si + ei)/2;
    int lsize = mid - si + 1;
    int rsize = ei - mid;
    mergeSort(input, lsize, si, mid);
    mergeSort(input , rsize, mid+1, ei);
    merge(input, si, ei);
    return;
}

int FwdLinearSearch(int *arr, int si, int ei, int x)
{
    int count = 0;
    for(int i=si; i<=ei; i++)
    {
        if(arr[i] == x)
            count++;
        else 
            break;
    }
    return count;
}

int BwdLinearSearch(int *arr, int si, int ei, int x)
{
    int count = 0;
    for(int i=si; i>=ei; i--)
    {
        if(arr[i] == x)
            count++;
        else
            break;
    }
    return count;
}

int sum_pair(int *arr, int size, int num)
{
    int count = 0;
    int i = 0, j = size - 1;
    while(i < j)
    {
        if(arr[i] + arr[j] == num)
        {
            if(arr[i] == arr[j])
            {
                count = count + (((j-i)*(j-i+1))/2);
                return count;
            }
            int FwdStep = FwdLinearSearch(arr, i+1, j-1, arr[i]);
            int BwdStep = BwdLinearSearch(arr, j-1, i+1, arr[j]);
            FwdStep += 1;
            BwdStep += 1;
            i += FwdStep;
            j -= BwdStep;
            count += FwdStep*BwdStep;
        }
        else if(arr[i] + arr[j] < num)
            i++;
        else 
            j--;
    }
    return (count);
}

int triplet_sum(int *arr, int size, int num)
{
    int count = 0;
    mergeSort(arr, size);

    for(int i=0; i<size; i++)
    {
        int *tempArr = new int[size-i-1];
        int tempNum = num - arr[i];
        if(tempNum > arr[i])
        {
            for(int j=i+1, k=0; j<size; j++)
                tempArr[k++] = arr[j];
            count = count + sum_pair(tempArr, size-i-1, tempNum);
        }
        else
            break;
    }
    return count;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int size, num;
        cin >> size;
        int *arr = new int[size];
        for(int i=0; i<size; i++)
            cin >> arr[i];
        cin >> num;
        cout << triplet_sum(arr, size, num) << endl;
    }
    return(0);
}