#include <iostream>
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
	// Write your code here
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

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}