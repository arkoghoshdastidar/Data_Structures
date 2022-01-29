#include <iostream>
using namespace std;

int binarySearch(int input[], int size, int element)
{
    // Write your code here
	if(size == 0)
        return(-1);
    
    int mid = 0;
    
    if(size%2 == 0)
        mid = (size-1)/2;
    else
        mid = size/2;
    
 	if(input[mid] == element)   
        return(mid);
    else if(input[mid] > element)
        return(binarySearch(input, mid, element));
    else{
        if(binarySearch(input+mid+1, size-mid-1, element) == -1)
            return(-1);
        else
             return(mid +1+ binarySearch(input+mid+1, size-mid-1, element));
    } 
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}