// Print Subset Sum to K
// Send Feedback
// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 

#include <iostream>
using namespace std;

void printSubsetSumToK(int input[], int inputSize, int key, int tempArr[], int tempArrSize)
{
    if(inputSize == 0)
    {
        int sum = 0;
        for(int i = 0; i<tempArrSize; i++)
        {
            sum += tempArr[i];
        }
        if(sum == key)
        {
            for(int i=0; i<tempArrSize; i++)
                cout << tempArr[i] << " ";
            cout << endl;
            return;
        }
        else
            return;
    }
    
    printSubsetSumToK(input+1, inputSize-1, key, tempArr, tempArrSize);
    tempArr[tempArrSize] = input[0];
    printSubsetSumToK(input+1, inputSize-1, key, tempArr, tempArrSize + 1);
    return;
}

void printSubsetSumToK(int input[], int size, int k)
{
    int tempArr[1000];
    return(printSubsetSumToK(input, size, k, tempArr, 0));
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}