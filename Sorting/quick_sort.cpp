#include<iostream>
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int si, int ei){
    int count = 0;
    
    for(int i=si+1; i <= ei; i++){
        if(a[i] <= a[si])
            count++;
    }
    
    swap(a[si], a[si+count]);
    int i = si, j = ei;
    
    while(i < si+count && j > si+count)
    {
    	if(a[i] <= a[si+count])
            i++;
        if(a[j] > a[si+count])
            j--;
        if(a[i] > a[si+count] && a[j] <= a[si+count]){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return(si + count);
}

void quickSort(int input[], int si, int ei){
    if(si >= ei)
        return;
    int pivot = partition(input, si, ei);
    quickSort(input, si, pivot-1);
    quickSort(input, pivot+1,ei);
}

void quickSort(int input[], int size){
	quickSort(input, 0, size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}